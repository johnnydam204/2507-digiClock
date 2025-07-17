#include "hal_gpio.h"
#include "esp_log.h"
#include "string.h"
#include "unistd.h"

static const char *TAG = "HAL_GPIO";

void HAL_GPIO_Init(gpio_config_t *config)
{
    esp_err_t ret = gpio_config(config);
    if (ret != ESP_OK) 
    {
        ESP_LOGE(TAG, "Failed to configure GPIO for 74HC595: %s", esp_err_to_name(ret));
    } 
    else 
    {
        ESP_LOGI(TAG, "GPIO initialized successfully");
    }
}

esp_err_t HAL_GPIO_SetDirection(gpio_num_t gpio_num, gpio_mode_t mode)
{
    gpio_set_direction(gpio_num, mode);
    return ESP_OK;
}

esp_err_t HAL_GPIO_SetLevel(gpio_num_t gpio_num, uint32_t level)
{
    gpio_set_level(gpio_num, level);
    return ESP_OK;
}

int HAL_GPIO_GetLevel(gpio_num_t gpio_num)
{  
    return gpio_get_level(gpio_num);
}

esp_err_t HAL_GPIO_PullupEn(gpio_num_t gpio_num)
{
    gpio_pullup_en(gpio_num);
    return ESP_OK;
}

esp_err_t HAL_GPIO_PullupDis(gpio_num_t gpio_num)
{
    gpio_pullup_dis(gpio_num);
    return ESP_OK;
}

esp_err_t HAL_GPIO_PulldownEn(gpio_num_t gpio_num)
{
    gpio_pulldown_en(gpio_num);
    return ESP_OK;
}

esp_err_t HAL_GPIO_PulldownDis(gpio_num_t gpio_num)
{
    gpio_pulldown_dis(gpio_num);
    return ESP_OK;
}


// End of file: components/hals/src/hal_gpio.c
