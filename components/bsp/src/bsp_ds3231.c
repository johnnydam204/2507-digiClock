#include "bsp_ds3231.h"

void BSP_Ds3231_Init(void)
{
    esp_err_t ret = HAL_I2C_Init(I2C0_PORT, I2C_MODE_MASTER, I2C0_SCL, I2C0_SDA, true, DS3231_I2C_FREQ_HZ, DS3231_I2C_ADDRESS);
    if (ret != ESP_OK) 
    {
        return ret;
    }
}

void BSP_DS3231_GetTime(tm *tm)
{
    uint8_t data[7];
    esp_err_t ret = HAL_I2C_Read(I2C0_PORT, DS3231_I2C_ADDRESS, 0x00, data, sizeof(data), DS3231_I2C_TIMEOUT_MS);
    if (ret != ESP_OK) 
    {
        return ret;
    }

    tm->tm_sec = bcd_to_dec(data[0] & 0x7F);
    tm->tm_min = bcd_to_dec(data[1] & 0x7F);
    tm->tm_hour = bcd_to_dec(data[2] & 0x3F);
    tm->tm_wday = data[3] & 0x07;
    tm->tm_mday = bcd_to_dec(data[4] & 0x3F);
    tm->tm_mon = bcd_to_dec(data[5] & 0x1F) - 1; // Month is zero-based
    tm->tm_year = bcd_to_dec(data[6]) + 100; // Year since 1900
}

void BSP_DS3231_SetTime(const tm *tm)
{
    uint8_t data[7];
    data[0] = dec_to_bcd(tm->tm_sec);
    data[1] = dec_to_bcd(tm->tm_min);
    data[2] = dec_to_bcd(tm->tm_hour);
    data[3] = tm->tm_wday & 0x07; // Day of week
    data[4] = dec_to_bcd(tm->tm_mday);
    data[5] = dec_to_bcd(tm->tm_mon + 1); // Month is one-based
    data[6] = dec_to_bcd(tm->tm_year - 100); // Year since 1900

    esp_err_t ret = HAL_I2C_Write(I2C0_PORT, DS3231_I2C_ADDRESS, 0x00, data, sizeof(data), DS3231_I2C_TIMEOUT_MS);
    if (ret != ESP_OK) 
    {
        return ret;
    }
}

void BSP_DS3231_GetTemperature(float *temp)
{
    uint8_t data[2];
    esp_err_t ret = HAL_I2C_Read(I2C0_PORT, DS3231_I2C_ADDRESS, 0x11, data, sizeof(data), DS3231_I2C_TIMEOUT_MS);
    if (ret != ESP_OK) 
    {
        return ret;
    }

    int16_t temp_raw = (data[0] << 8) | data[1];
    *temp = (float)temp_raw / 256.0f; // Convert to degrees Celsius
}
