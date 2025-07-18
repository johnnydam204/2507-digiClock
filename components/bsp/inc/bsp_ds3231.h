/**
 * ******************************************************************************************
 * @file bsp_ds3231.h
 * @brief Board Support Package for the DS3231 RTC module
 * @author Johnny
 * @date 2025/07
 * @version 1.0
 * ******************************************************************************************
 **/
 
#ifndef __BSP_DS3231_H__
#define __BSP_DS3231_H__ 

#include <stdint.h>
#include "hal_i2c.h"
#include "cfg_board_hw.h" // Include hardware board configuration

#ifdef __cplusplus
extern "C" {
#endif

#define DS3231_I2C_SDA I2C0_SDA     // SDA pin for I2C1 Peripheral
#define DS3231_I2C_SCL I2C0_SCL     // SCL pin for I2C1 Peripheral
#define DS3231_I2C_PORT I2C_NUM_0   // I2C port number for DS3231 RTC

#define DS3231_I2C_FREQ_HZ      1000    // I2C frequency for DS3231 RTC
#define DS3231_I2C_TIMEOUT_MS   1000    // I2C timeout for DS3231 RTC operations
#define DS3231_I2C_ADDRESS      0x68    // I2C address for DS3231 RTC


/**
 * @brief Initialize the DS3231 RTC module
 *
 * This function initializes the I2C interface and configures the DS3231
 * RTC module for operation.
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */
void BSP_Ds3231_Init(void);
/**
 * @brief Read the current time from the DS3231 RTC
 *
 * This function reads the current time from the DS3231 RTC and stores it
 * in a `struct tm` format.
 *
 * @param tm Pointer to a `struct tm` where the current time will be stored
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */
void BSP_DS3231_GetTime(struct tm *tm);
/**
 * @brief Set the current time on the DS3231 RTC
 *
 * This function sets the current time on the DS3231 RTC using a `struct tm`
 * format.
 *
 * @param tm Pointer to a `struct tm` containing the time to set
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */

void BSP_DS3231_SetTime(const struct tm *tm);
/**
 * @brief Read the current temperature from the DS3231 RTC
 *
 * This function reads the current temperature from the DS3231 RTC.
 *
 * @param temp Pointer to a float where the temperature in degrees Celsius will be stored
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */
void BSP_DS3231_GetTemperature(float *temp);


#endif // __BSP_DS3231_H__

// End of file: components/bsp/inc/bsp_ds3231.h
