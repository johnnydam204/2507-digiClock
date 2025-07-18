#include "esp_log.h"
#include "esp_check.h"
#include "inf_display.h"

static const char *TAG = "INF_DISPLAY";

// End of file: components/interface/src/inf_7seg_disp.c
esp_err_t INF_Display_Init(void)
{   
    BSP_Led7Seg_Init();
    return ESP_OK;
}

esp_err_t INF_Display_Time(uint8_t hour, uint8_t minute, uint8_t second)
{
    uint8_t hours[2];
    uint8_t minutes[2]; 
    uint8_t seconds[2];

    // Convert hour, minute, and second to two-digit format
    hours[0] = hour / 10; // Tens place
    hours[1] = hour % 10; // Units place
    minutes[0] = minute / 10; // Tens place
    minutes[1] = minute % 10; // Units place    
    seconds[0] = second / 10; // Tens place
    seconds[1] = second % 10; // Units place

    // Validate the input values
    ESP_RETURN_ON_FALSE(hour < 24, ESP_ERR_INVALID_ARG, TAG, "Invalid hour: %d", hour);
    ESP_RETURN_ON_FALSE(minute < 60, ESP_ERR_INVALID_ARG, TAG, "Invalid minute: %d", minute);
    ESP_RETURN_ON_FALSE(second < 60, ESP_ERR_INVALID_ARG, TAG, "Invalid second: %d", second);

    // Display the time on the 7-segment display
    BSP_Led7Seg_PutNum(0, hours[0]); // Display tens of hour
    BSP_Led7Seg_PutNum(1, hours[1]); // Display units of hour
    BSP_Led7Seg_PutNum(2, minutes[0]); // Display tens  of minute
    BSP_Led7Seg_PutNum(3, minutes[1]); // Display units of minute
    BSP_Led7Seg_PutNum(4, seconds[0]); // Display tens                          
    BSP_Led7Seg_PutNum(5, seconds[1]); // Display units of second
    // Return success
    ESP_LOGI(TAG, "Time displayed: %02d:%02d:%02d", hour, minute, second);
    // Return ESP_OK to indicate success
    ESP_RETURN_ON_ERROR(ESP_OK, TAG, "Failed to display time on 7-segment display");
    ESP_RETURN_ON_ERROR(ESP_OK, TAG, "Failed to display time on 7-segment display");


    return ESP_OK;
}
