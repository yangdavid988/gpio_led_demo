#ifndef _GPIO_LDE_DEMO_H_
#define _GPIO_LDE_DEMO_H_

#include "ameba_soc.h"
// #include "ameba_gpio.h"
#include "os_wrapper.h"
#include <stdio.h>
#include "platform_autoconf.h"


//定义三个gpio对应的evb pin idex
#define LED1_PIN _PA_14
#define LED2_PIN _PA_15
#define LED3_PIN _PA_16

void gpio_led_init(void);
void gpio_led_toggle(void);

#endif
