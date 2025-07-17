/**
 * @file bsp_led7seg.h
 * @brief Header file for the BSP driver for 7-segment LED display
 * @author Johnny
 * @date 2025-07-03
 * @note This driver is designed to be used with the ESP-IDF framework and is compatible with various ESP32-based development boards.
 * @version 1.0
*/

#ifndef __BSP_LED7SEG_H__
#define __BSP_LED7SEG_H__

#include <stdint.h>
#include "esp_err.h"
#include "hw_board_cfg.h"
#include "bsp_74hc595.h"

#ifdef __cplusplus
extern "C" {   
#endif

#define NUM_DIGITS  SEG_LED_NUM_DIGI // Number of digits in the 7-segment display, SEG_LED_NUM_DIGI from hw_board_cfg.h

/**
 * @brief Initialize the 7-segment LED display
 * @param None
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t BSP_Led7Seg_Init(void);

/**
 * @brief Display a number on the 7-segment LED display
 * @param pos Position of the digit to display (0 to NUM_DIGITS-1)
 * @param num Number to display (0 to 9)
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t BSP_Led7Seg_PutNum(uint8_t pos, uint8_t num);

/**
 * @brief Clear Display (write blank) on the 7-segment LED display
 * @param none
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t BSP_Led7Seg_Clear(void);


#endif // __BSP_LED7SEG_H__

//End of file: components/interface/inc/inf_7seg_disp.h
