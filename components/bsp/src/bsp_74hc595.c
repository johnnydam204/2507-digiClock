#include "bsp_74hc595.h"
#include "esp_log.h"
#include "esp_check.h"

static const char *TAG = "BSP_74HC595";

esp_err_t BSP_74hc595_Init(void) 
{
    ESP_LOGI(TAG, "Initializing 74HC595...");

    // Initialize GPIO pins for 74HC595
    HAL_GPIO_SetDirection(GPIO_74HC595_DS, GPIO_MODE_OUTPUT);
    HAL_GPIO_SetDirection(GPIO_74HC595_SHCP, GPIO_MODE_OUTPUT); 
    HAL_GPIO_SetDirection(GPIO_74HC595_STCP, GPIO_MODE_OUTPUT);

    // Set initial levels for the GPIO pins
    HAL_GPIO_SetLevel(GPIO_74HC595_DS, 0);
    HAL_GPIO_SetLevel(GPIO_74HC595_SHCP, 1);
    HAL_GPIO_SetLevel(GPIO_74HC595_STCP, 1);

    return ESP_OK;
}

esp_err_t BSP_74hc595_SendData(uint8_t data)
{
    // Send data to 74HC595 shift register
    for (int i = 0; i < 8; i++) 
    {
        // Set data pin
        HAL_GPIO_SetLevel(GPIO_74HC595_DS, (data >> (7 - i)) & 0x01);
        
        // Pulse the shift clock pin
        BSP_74hc595_Clock(); 
    }    
    return ESP_OK;
}

esp_err_t BSP_74hc595_Clear(void)
{
    // Clear the 74HC595 shift register by sending 0x00
    BSP_74hc595_SendData(0x00);
    return ESP_OK;
}

esp_err_t BSP_74hc595_Clock(void)
{
    // Set the storage clock pin high
    HAL_GPIO_SetLevel(GPIO_74HC595_STCP, 1);
    // Set the storage clock pin low
    HAL_GPIO_SetLevel(GPIO_74HC595_STCP, 0);
    return ESP_OK;
}

esp_err_t BSP_74hc595_Latch(void)
{
    // Set the latch pin high to latch the data
    gpio_set_level(GPIO_74HC595_STCP, 1);
    // Set the latch pin low to complete the latching
    gpio_set_level(GPIO_74HC595_STCP, 0);
    return ESP_OK;
}

