#include "esp_log.h"
#include "esp_check.h"
#include "bsp_led7seg.h"

static void BSP_Led7Seg_Update(const uint8_t* data_array, uint8_t count);

static const char *TAG = "BSB_LED7SEG";

static uint8_t g_led_display_data[NUM_DIGITS] = {0}; // Mảng lưu trữ mã hiển thị cho từng vị trí của 7-segment display

esp_err_t BSP_Led7Seg_Init(void)
{
    BSP_74hc595_Init();
    return ESP_OK;
}

esp_err_t BSP_Led7Seg_PutNum(uint8_t pos, uint8_t num)
{
    if (pos >= NUM_DIGITS) 
    {
        return ESP_ERR_INVALID_ARG; 
    }

    // Lấy mã 7 đoạn tương ứng với số
    uint8_t led_code = (num > 9) ? LED_CODE[10] : LED_CODE[num];
    
    // 1. Cập nhật giá trị tại vị trí mong muốn trong mảng dữ liệu
    g_led_display_data[pos] = led_code;

    // 2. Gọi hàm BSP để gửi toàn bộ mảng dữ liệu mới ra phần cứng
    BSP_Led7Seg_Update(g_led_display_data, NUM_DIGITS);    
    return ESP_OK;
}

static void BSP_Led7Seg_Update(const uint8_t* data_array, uint8_t count)
{
    // Kiểm tra dữ liệu hợp lệ
    if (data_array == NULL || count == 0) 
    {
        ESP_LOGE(TAG, "Invalid data array or count");
        return;
    }

    // Gửi dữ liệu đến 74HC595
    for (uint8_t i = 0; i < count; i++) 
    {
        BSP_74hc595_SendData(data_array[i]);
    }

    // Latch dữ liệu để hiển thị
    BSP_74hc595_Latch();
}

