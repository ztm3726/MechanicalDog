#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_usart.h>
#include <stm32f4xx.h>
#include <misc.h>
#include <stdio.h>
#include "delay.h"
#include "pca9685.h"
#include "myiic.h"
#include "run.h"
#include "usart.h"
#include "wifi.h"

#define PA6_1 GPIO_SetBits(GPIOA, GPIO_Pin_6);
#define PA6_0 GPIO_ResetBits(GPIOA, GPIO_Pin_6);
#define PWM(n)  (int)(204.8 * (0.5 + n * 1.0 / 90))



void LedInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	PA6_1
}

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Usart1Init();
	Usart6Init();
	LedInit();
	delay_init(168);      
	IIC_Init();
	PCA9685_write(PCA9685_MODE1, 0x0);
	setPWMFreq(50);
	delay_ms(1000);
	while (1) 
	{
		switch (dat)
		{
		case 0x61:
			forward();
			break;
		case 0x62:
			backup();
			break;
		case 0x63:
			left();
			break;
		case 0x64:
			right();
			break;
		default:
			motionless();
		}
	}
}
