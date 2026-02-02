#ifndef _GPIO_LDE_DEMO_H_
#define _GPIO_LDE_DEMO_H_

#include "ameba_soc.h"
#include "os_wrapper.h"
#include <stdio.h>
#include "platform_autoconf.h"


//定义三个gpio对应的evb pin idex
#define LED1_PIN _PA_14 //G
#define LED2_PIN _PA_15 //R
#define LED3_PIN _PA_16 //B

void gpio_led_init(void);
void gpio_led_toggle(void);

#endif
