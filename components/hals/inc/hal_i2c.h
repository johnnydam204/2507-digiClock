/**
 * @file hal_i2c.h
 * @brief HAL driver for I2C
 * This header file provides the interface for the HAL driver that
 * interacts with I2C devices.
 * @author Johnny
 * @date 2025-07-03
 */

#ifndef __HAL_I2C_H__
#define __HAL_I2C_H__

#include <stdint.h>
#include "esp_err.h"
#include "driver/i2c.h"
#include "hw_board_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    i2c_port_t port;         //I2C port number
    i2c_config_t cfg;        //I2C driver configuration
    uint8_t addr;            //Unshifted address
    SemaphoreHandle_t mutex; //Device mutex
    uint32_t timeout_ticks;  /*HW I2C bus timeout (stretch time), in ticks. 80MHz APB clock
                                  ticks for ESP-IDF, CPU ticks for ESP8266.
                                  When this value is 0, I2CDEV_MAX_STRETCH_TIME will be used */
} HAL_I2cDev_t;

#ifndef I2CDEV_MAX_STRETCH_TIME
#define I2CDEV_MAX_STRETCH_TIME 1000 // Default value in ticks, adjust as needed
#endif

/**
 * @brief Initialize the I2C HAL
 *
 * This function initializes the I2C HAL, setting up necessary configurations.
 *
 * @param port The I2C port number
 * @param mode The I2C mode (master or slave)
 * @param scl_io_num GPIO number for I2C SCL signal
 * @param sda_io_num GPIO number for I2C SDA signal
 * @param isPullup Enable internal pull-up for SDA and SCL (TRUE/FALSE)
 * @param clk_speed I2C clock frequency in Hz
 * @param addr I2C device address (7-bit)
 * @return
 * - ESP_OK on success
 * - ESP_ERR_INVALID_ARG if the arguments are invalid
 * - ESP_ERR_NO_MEM if memory allocation fails
 */
void HAL_I2C_Init(i2c_port_t port, i2c_mode_t mode, int scl_io_num, int sda_io_num, bool isPullup, uint32_t clk_speed, uint8_t addr);

/**
 * @brief Read data from an I2C device
 *
 * This function reads data from an I2C device.
 *
 * @param dev_addr The I2C device address
 * @param reg_addr The register address to read from
 * @param data Pointer to the buffer to store the read data
 * @param len Number of bytes to read
 * @return
 * - ESP_OK on success
 * - ESP_ERR_INVALID_ARG if the arguments are invalid
 * - ESP_FAIL on failure
 */
void HAL_I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t len);

#endif // __HAL_I2C_H__

// End of file: components/hals/inc/hal_i2c.h






