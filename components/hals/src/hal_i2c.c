#include "hal_i2c.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"


esp_err_t HAL_I2C_Init(i2c_port_t port, i2c_mode_t mode, int scl_io_num, int sda_io_num, bool isPullup, uint32_t clk_speed, uint8_t addr) 
{
    HAL_I2cDev_t *dev = (HAL_I2cDev_t *)malloc(sizeof(HAL_I2cDev_t));
    if (!dev) 
    {
        return ESP_ERR_NO_MEM;
    }

    dev->port = port;
    dev->cfg.mode = mode;
    dev->cfg.sda_io_num = sda_io_num;
    dev->cfg.scl_io_num = scl_io_num;
    dev->cfg.sda_pullup_en = isPullup; // Enable internal pull-up for SDA
    dev->cfg.scl_pullup_en = isPullup; // Enable internal pull-up for SCL
    dev->cfg.master.clk_speed = clk_speed;
    dev->addr = addr << 1; // Shift address for 7-bit addressing
    dev->mutex = xSemaphoreCreateMutex();
    if (dev->mutex == NULL) 
    {
        free(dev);
        return ESP_ERR_NO_MEM;
    }
    
    // Initialize I2C driver
    esp_err_t ret = i2c_param_config(port, &dev->cfg);
    if (ret != ESP_OK) 
    {
        vSemaphoreDelete(dev->mutex);
        free(dev);
        return ret;
    }

    ret = i2c_driver_install(port, mode, 0, 0, 0);
    if (ret != ESP_OK) 
    {
        vSemaphoreDelete(dev->mutex);
        free(dev);
        return ret;
    }

    // Set the device timeout ticks
    dev->timeout_ticks = (80 * 1000 * 1000) / clk_speed; // Convert clock speed to ticks
    if (dev->timeout_ticks == 0) {  
        dev->timeout_ticks = I2CDEV_MAX_STRETCH_TIME; // Use default stretch time if calculated value is zero
    }   

    return ESP_OK;
}

void HAL_I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t len)
{
    HAL_I2cDev_t *dev = (HAL_I2cDev_t *)malloc(sizeof(HAL_I2cDev_t));
    if (!dev) 
    {
        ESP_LOGE("HAL_I2C", "Failed to allocate memory for I2C device");
        return;
    }

    if (xSemaphoreTake(dev->mutex, portMAX_DELAY) != pdTRUE) 
    {
        ESP_LOGE("HAL_I2C", "Failed to take I2C mutex");
        free(dev);
        return;
    }

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, dev->addr | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg_addr, true);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, dev->addr | I2C_MASTER_READ, true);
    
    if (len > 1) 
    {
        i2c_master_read(cmd, data, len - 1, I2C_MASTER_ACK);
    }
    
    i2c_master_read_byte(cmd, data + len - 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd);

    esp_err_t ret = i2c_master_cmd_begin(dev->port, cmd, dev->timeout_ticks / portTICK_PERIOD_MS);
    if (ret != ESP_OK) 
    {
        ESP_LOGE("HAL_I2C", "I2C read failed: %s", esp_err_to_name(ret));
    }

    i2c_cmd_link_delete(cmd);
    xSemaphoreGive(dev->mutex);
    free(dev);
}
