#ifndef __USART_H
#define __USART_H
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_usart.h>
#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <misc.h>
#include <stdio.h>

void Usart1Init(void);
char* GetUsartData(void);

#endif
