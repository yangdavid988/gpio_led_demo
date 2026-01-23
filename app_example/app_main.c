#include "gpio_led_demo.h"
#include "FreeRTOS.h"
#include "task.h"

#define TAG "app_main" 

void app_example(void)
{
    RTK_LOGI(TAG, "gpio_led_demo start!\r\n");
    gpio_led_init();//初始化LED    

    if (rtos_task_create( NULL, "gpio_led_toggle", (rtos_task_t)gpio_led_toggle, NULL, 1024, tskIDLE_PRIORITY + 2 ) != RTK_SUCCESS )
    {
        RTK_LOGE(TAG, "gpio_led_toggle failed!\r\n");
    }   
}
    