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

#define PA6_1 GPIO_SetBits(GPIOA, GPIO_Pin_6);
#define PA6_0 GPIO_ResetBits(GPIOA, GPIO_Pin_6);
#define PWM(n)  (int)(204.8 * (0.5 + n * 1.0 / 90))

unsigned char RES;

/* 重定向printf函数 */
int _write(int fd, char *pBuffer, int size)  
{  
	int i = 0;
	for (i = 0; i < size; i++)  
	{  
		while ((USART1->SR & 0X40) == 0) ;			//等待上一次串口数据发送完成  
		USART1->DR = (uint8_t) pBuffer[i];          //写DR,串口1将发送数据
	}  
	return size;  
}

void Init_Usart(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStructure);
	
	USART_Cmd(USART1, ENABLE);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

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
}

/* 串口1接收中断 */
void USART1_IRQHandler()
{
	if (USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		RES = USART_ReceiveData(USART1);
		USART_SendData(USART1, RES);
	}
}

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Init_Usart();
	delay_init(168);      
	IIC_Init();
	PCA9685_write(PCA9685_MODE1, 0x0);
	setPWMFreq(50);
	motionless();
	delay_ms(1000);
	while (1) 
	{
		u16 pwm = calculate_PWM(80);
		printf("hello\r\n");
		/*for (int i = 100; i >= 80; i--)
		{
			setPWM(10, 0, PWM(i));
			delay_ms(60);
		}
		for (int i = 80; i <= 100; i++)
		{
			setPWM(10, 0, PWM(i));
			delay_ms(60);
		}*/
		forward();
		//delay_ms(500);
	}
}
