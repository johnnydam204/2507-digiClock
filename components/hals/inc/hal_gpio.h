/**
 * @file hal_gpio.h
 * @brief HAL driver for GPIO
 * This header file provides the interface for the HAL driver that
 * interacts with GPIO pins.    
 * @author Johnny
 * @date 2025-07-03
 */

#ifndef __HAL_GPIO_H__
#define __HAL_GPIO_H__

#include <stdint.h>
#include <stdbool.h>
#include "driver/gpio.h"
#include "esp_err.h"


/**
 * @brief Set the direction of a GPIO pin.
 * @param gpio_num The GPIO pin number.
 * @param mode The mode to set (e.g., GPIO_MODE_INPUT, GPIO_MODE_OUTPUT).
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_SetDirection(gpio_num_t gpio_num, gpio_mode_t mode);
/**
 * @brief Set the level of a GPIO pin.
 * @param gpio_num The GPIO pin number.
 * @param level The level to set (0 for low, 1 for high).
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_SetLevel(gpio_num_t gpio_num, uint32_t level);
/**
 * @brief Get the level of a GPIO pin.
 * @param pin The GPIO pin number.
 * @return The current level of the pin (high or low).
 */
int HAL_GPIO_GetLevel(gpio_num_t gpio_num);
/**
 * @brief Set the pull-up resistors for a GPIO pin.
 * @param pin The GPIO pin number.
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_PullupEn(gpio_num_t gpio_num);
/**
 * @brief Clear the pull-up resistors for a GPIO pin.
 * @param pin The GPIO pin number.
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_PullupDis(gpio_num_t gpio_num);
/**
 * @brief Set the pull-down resistors for a GPIO pin.
 * @param pin The GPIO pin number.
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_PulldownEn(gpio_num_t gpio_num);
/**
 * @brief Clear the pull-down resistors for a GPIO pin.
 * @param pin The GPIO pin number.
 * @return ESP_OK on success, or an error code on failure.
 */
esp_err_t HAL_GPIO_PulldownDis(gpio_num_t gpio_num);

/**
 * @brief Set the interrupt type for a GPIO pin.
 * @param pin The GPIO pin number.
 * @param intr_type The type of interrupt (e.g., rising edge, falling edge).
 */
void HAL_GPIO_SetIntrType(gpio_num_t pin, gpio_int_type_t intr_type);

/**
 * @brief Install GPIO ISR service.
 * This function installs the GPIO ISR service, allowing for interrupt handling.
 */
esp_err_t HAL_GPIO_InstallIsrService(void);

/**
 * @brief Uninstall GPIO ISR service.
 * This function uninstalls the GPIO ISR service, cleaning up resources.
 */
esp_err_t HAL_GPIO_UninstallIsrService(void);

/**
 * @brief Register a GPIO ISR handler.
 * @param pin The GPIO pin number.
 * @param handler The ISR handler function to be called on interrupt.
 * @param arg Argument to be passed to the handler.
 */
esp_err_t HAL_GPIO_IsrHandlerAdd(gpio_num_t pin, gpio_isr_t handler, void *arg);

/**
 * @brief Remove a GPIO ISR handler.
 * @param pin The GPIO pin number.
 */
esp_err_t HAL_GPIO_IsrHandlerRemove(gpio_num_t pin);

/**
 * @brief Clear the interrupt status for a GPIO pin.
 * @param pin The GPIO pin number.
 */
esp_err_t HAL_GPIO_IntrClear(gpio_num_t pin);

/**
 * @brief Set the GPIO pin to a specific mode.
 * @param pin The GPIO pin number.
 * @param mode The mode to set (e.g., GPIO_MODE_INPUT, GPIO_MODE_OUTPUT).
 */
esp_err_t HAL_GPIO_SetMode(gpio_num_t pin, gpio_mode_t mode);
/**
 * @brief Get the current mode of a GPIO pin.
 * @param pin The GPIO pin number.
 * @return The current mode of the pin.
 */
esp_err_t HAL_GPIO_GetMode(gpio_num_t pin, gpio_mode_t *mode);

#endif // __HAL_GPIO_H__

// End of hal_gpio.h






