#include "gpio_led_demo.h"

// @brief  GPIO Init Structure Definition
  
// typedef struct {
// 	u32 GPIO_Mode;			/*!< Specifies the operating mode for the selected pins.
// 								This parameter can be a value of @ref GPIO_Mode */

// 	u32 GPIO_PuPd;			/*!< Specifies the operating Pull-up/Pull down for the selected pins.
// 								This parameter can be a value of @ref GPIO_Pull_Type */

// 	u32 GPIO_ITTrigger;		/*!< Specifies interrupt mode is level or edge trigger
// 								This parameter can be a value of @ref GPIO_INT_Trigger_Type */

// 	u32 GPIO_ITPolarity;	/*!< Specifies interrupt mode is high or low active trigger
// 								This parameter can be a value of @ref GPIO_INT_Polarity_Type */

// 	u32 GPIO_ITDebounce;	/*!< Specifies enable or disable de-bounce for interrupt
// 								This parameter can be a value of @ref GPIO_INT_Debounce_Type*/

// 	u32 GPIO_Pin;			/*!< Specifies the selected pins.
// 								This parameter contains two parts: Pin[7:5]: port number; Pin[4:0]: pin number */
// } GPIO_InitTypeDef; 

void gpio_led_init()
{    
    //定义三个gpio给LED使用
    GPIO_InitTypeDef led1_gpio;
    GPIO_InitTypeDef led2_gpio;
    GPIO_InitTypeDef led3_gpio;

    //初始化LED 对应的GPIO io
    led1_gpio.GPIO_Pin = LED1_PIN;
    led2_gpio.GPIO_Pin = LED2_PIN;
    led3_gpio.GPIO_Pin = LED3_PIN;

    //GPIO mode == out
    led1_gpio.GPIO_Mode = GPIO_Mode_OUT;
    led2_gpio.GPIO_Mode = GPIO_Mode_OUT;
    led3_gpio.GPIO_Mode = GPIO_Mode_OUT;

    //GPIO init
    GPIO_Init(&led1_gpio); 
    GPIO_Init(&led2_gpio); 
    GPIO_Init(&led3_gpio); 
   
    printf("gpio_led_setup ready!\r\n");
    //LED 全部亮一次后再全灭
    GPIO_WriteBit(LED1_PIN, 1);
    GPIO_WriteBit(LED2_PIN, 1);
    GPIO_WriteBit(LED3_PIN, 1);
    rtos_time_delay_ms(1000);
    GPIO_WriteBit(LED1_PIN, 0);
    GPIO_WriteBit(LED2_PIN, 0);
    GPIO_WriteBit(LED3_PIN, 0); 
    rtos_time_delay_ms(2000);   
    return;
}

void gpio_led_toggle()
{    
    int i = 0;
    while (1)
    {
         //led toggle，间隔1s切换一次gpio
        GPIO_WriteBit(LED1_PIN, 1);
        rtos_time_delay_ms(1000);

        GPIO_WriteBit(LED1_PIN, 0);
        GPIO_WriteBit(LED2_PIN, 1);
        rtos_time_delay_ms(1000);

        GPIO_WriteBit(LED2_PIN, 0);
        GPIO_WriteBit(LED3_PIN, 1);
        rtos_time_delay_ms(1000);

        GPIO_WriteBit(LED3_PIN, 0);
        printf("==> LED toggle count:%d\r\n", ++i);   
    }    
    rtos_task_delete(NULL);
}