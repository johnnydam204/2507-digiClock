/**
 * @file bsp_74hc595.h
 * @brief This file is part of the BSP (Board Support Package) for the 74HC595 shift register.
 * This file contains function declarations for initializing, sending data to,
 * clearing, and latching the output of the 74HC595 shift register.
 * This driver is designed to work with the ESP-IDF framework and uses GPIO pins
 * for communication with the 74HC595 shift register.
 * @note The GPIO pins used for the 74HC595 are defined in the hw_board_cfg.h file.
 * @author Johnny 
 * @date 2023-10-01
 * @version 1.0
 */

#ifndef __BSP_74HC595_H__
#define __BSP_74HC595_H__

#include <stdint.h>
#include "esp_err.h"
#include "hal_gpio.h"
#include "hw_board_cfg.h"

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