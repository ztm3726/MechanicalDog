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
#include "hcsr04.h"

#define PA6_ON GPIO_SetBits(GPIOA, GPIO_Pin_6);
#define PA6_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_6);
#define PWM(n)  (int)(204.8 * (0.5 + n * 1.0 / 90))

void LedInit()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_6 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	PA6_ON
		
    GPIOA->MODER &= ~(3 << (8 * 2));
}

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	Usart1Init();
	Usart6Init();
	LedInit();
	HcInit();
	IIC_Init();
	PCA9685_write(PCA9685_MODE1, 0x0);
	setPWMFreq(50);
	while (1) 
	{
		//setPWM(12, 0, PWM(100));
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
		case 0x65:
			moveleft();
			break;
		case 0x66:
			moveright();
			break;
		case 0x68:
			sitdowm();
			break;
		case 0x69:
			avoidance();
		default:
			motionless();
			break;
		}
		//printf("%d\r\n", cou);
		if (PAin(8))
			PA6_OFF
		else if(!PAin(8))
			PA6_ON
	}
}
