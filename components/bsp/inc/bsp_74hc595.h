/**
 * ******************************************************************************************
 * @file bsp_74hc595.h
 * @brief Board Support Package for the 74HC595 shift register
 * @author Johnny
 * @date 2025/07
 * @version 1.0
 * ******************************************************************************************
 **/

#ifndef __BSP_74HC595_H__
#define __BSP_74HC595_H__

#include <stdint.h>
#include "esp_err.h"
#include "hal_gpio.h"
#include "cfg_board_hw.h" // Include hardware board configuration

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations for HAL driver for 74HC595 Shift Register
// Hardware GPIO pin definitions for 74HC595
#define GPIO_74HC595_DS     SCLK    // Data pin for 74HC595
#define GPIO_74HC595_SHCP   SDAT    // Shift clock pin for 74HC595
#define GPIO_74HC595_STCP   SCLK    // Storage clock pin for 74HC595

/**
 * @brief Initialize the 74HC595 shift register
 *
 * This function initializes the GPIO pins used for the 74HC595 shift register.
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */ 
esp_err_t BSP_74hc595_Init(void);

/**
 * @brief Send data to the 74HC595 shift register
 *
 * This function sends a byte of data to the 74HC595 shift register.
 *
 * @param data The byte of data to send
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */
esp_err_t BSP_74hc595_SendData(uint8_t data);

/**
 * @brief Clear the 74HC595 shift register
 *
 * This function clears the output of the 74HC595 shift register.
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */ 
esp_err_t BSP_74hc595_Clear(void);

/**
 * @brief Clock the 74HC595 shift register
 * @param This function pulses the clock pin of the 74HC595 shift register to shift data.
 * @return ESP_OK on success or an error code on failure.
 */
esp_err_t BSP_74hc595_Clock(void);

/**
 * @brief Latch the output of the 74HC595 shift register
 *
 * This function latches the output of the 74HC595 shift register.
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL on failure
 */
esp_err_t BSP_74hc595_Latch(void);

#endif // __BSP_74HC595_H__

// End of hal_74hc595.h