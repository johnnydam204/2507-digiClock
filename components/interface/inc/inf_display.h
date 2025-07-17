/**
 * @file inf_display.h
 * @brief Header file for the interface of 7-segment display using a shift register (74HC595).
 * @author Johnny
 * @date 2025-07-03
 * @version 1.0
 */

#ifndef __INF_DISPLAY_H__
#define __INF_DISPLAY_H__

#include <stdint.h>
#include "bsp_led7seg.h"    // Include the header for the 74HC595 shift register
#include "hw_board_cfg.h"   // Include hardware board configuration

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the display interface.
 * @param None
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t INF_Display_Init(void);

/**
 * @brief Displays time data on the 7-segment display.
 * @param hỏur Hour value (0-23).
 * @param minute Minute value (0-59).   
 * @param second Second value (0-59).
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t INF_Display_Time(uint8_t hour, uint8_t minute, uint8_t second);


#endif // __INF_DISPLAY_H__

// End of file: components/interface/inc/inf_display.h