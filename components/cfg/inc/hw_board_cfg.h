/**
 * @file hw_board_cfg.h
 * @brief Hardware board configuration header file
 * 
 * This header file contains the hardware configuration for the board,
 * including GPIO pin definitions and other hardware-related settings.
 * 
 * @author Johnny
 * @date 2025-07-03
 */

#ifndef __HW_BOARD_CFG_H__
#define __HW_BOARD_CFG_H__

#include <stdint.h>
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C"  {
#endif  

// Hardware GPIO pin definitions for Shift Register 74HC595
#define SCLK    GPIO_NUM_25     // Shift clock pin for Shift Register 74HC595
#define SDAT    GPIO_NUM_33     // Data pin for Shift Register 74HC595
#define SLCH    GPIO_NUM_32     // Latch Storage clock pin for Shift Register 74HC595

// Hardware GPIO pin definitions for 7-Segment Display
#define SEG_LED_NUM_DIGI  6     // Number of 7-segment display digits (HH:MM:SS)
const uint8_t LED_CODE[11]= {0xFA,0xC0,0xB9,0xE9,0xC3,0x6B,0x7B,0xC8,0xFB,0xEB,0xFF}; // Segment codes for digits 0-9 and OFF

// Hardware definitions for I2C
#define I2C0_SDA   GPIO_NUM_22  // SDA pin for I2C0 Pheripheral
#define I2C0_SCL   GPIO_NUM_23  // SCL pin for I2C0 Pheripheral
#define I2C0_PORT  I2C_NUM_0    // I2C port number for I2C0 Peripheral


// Hardware GPIO pin definitions for Buttons
#define GPIO_BTN1       GPIO_NUM_36 // Button 1 pin
#define GPIO_BTN2       GPIO_NUM_39 // Button 2 pin
#define GPIO_BTN3       GPIO_NUM_34 // Button 3 pin
#define GPIO_BTN4       GPIO_NUM_35 // Button 4 pin

// Hardware GPIO pin definitions for Outputs
#define GPIO_OUT1       GPIO_NUM_27  // Output 1 pin
#define GPIO_OUT2       GPIO_NUM_14  // Output 2 pin
#define GPIO_OUT3       GPIO_NUM_12  // Output 3 pin    
#define GPIO_OUT4       GPIO_NUM_13  // Output 4 pin

// Hardware GPIO pin definitions for PWM Outputs
#define GPIO_PWM1       GPIO_NUM_26  // PWM Output 1 pin

// Hardware GPIO pin definitions for Buzzer
#define GPIO_BUZZER     GPIO_NUM_2   // Buzzer pin

// Hardware GPIO pin definitions for Encoder
#define GPIO_ENC_A      GPIO_NUM_16     // Encoder A pin
#define GPIO_ENC_B      GPIO_NUM_4      // Encoder B pin  
#define GPIO_ENC_PB     GPIO_NUM_17     // Encoder B pin  

// Hardware GPIO pin definitions for NPN Sensor
#define GPIO_NPN_SENSOR GPIO_NUM_5      // NPN Sensor pin

// Hardware GPIO pin definitions for PNP Sensor
#define GPIO_PNP_SENSOR GPIO_NUM_18     // PNP Sensor pin


// End of GPIO pin definitions

#endif // __HW_BOARD_CFG_H__