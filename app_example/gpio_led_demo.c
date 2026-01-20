#include "gpio_led_demo.h"


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
   
    return;
}