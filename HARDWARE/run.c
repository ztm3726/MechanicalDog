#include "run.h"

u8 avo = 0;
u8 break_flag = 1;
int avdis = 0;

void motionless()
{
	setPWM(0, 0, PWM(80));
	setPWM(1, 0, PWM(73));
	setPWM(2, 0, PWM(78));
	
	setPWM(3, 0, PWM(87));
	setPWM(13, 0, PWM(87));
	setPWM(5, 0, PWM(80));
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, PWM(90));
	setPWM(12, 0, PWM(83));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(78));
	setPWM(11, 0, PWM(74));	
}

void forward()
{
	//setPWM(0, 0, PWM(80));
	//setPWM(3, 0, PWM(87));
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	//1, 4
	//左前/右后（向前）
	for(int pwm_7 = 88, pwm_0 = 82, pwm_1 = 83, pwm_2 = 68, pwm_3 = 85, pwm_13 = 97, pwm_5 = 86, pwm_12 = 85, pwm_10 = 68, pwm_11 = 88 ; pwm_7 <= 108 ; pwm_7++)
	{
		if (pwm_0 >= 78) pwm_0--;
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_3 <= 89) pwm_3++;
		if (pwm_13 >= 77) pwm_13 --;
		if (pwm_5 >= 74) pwm_5 -=2;
		if (pwm_12 >= 70) pwm_12 -= 2;
		if (pwm_10 <= 88) pwm_10++;
		if (pwm_11 >= 74) pwm_11 -= 2;
		
		setPWM(0, 0, PWM(pwm_0)); 
		setPWM(1, 0, PWM(pwm_1)); 
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (!avo)
		{
			if (dat != 0x61)
				return;
		}
		else
		{
			avdis = GetHcData();
			if (avdis <= 32)
				return;
			if (cou == 2)
			{
				u8 break_flag = 0;
				return;
			}
		}
		delay_ms(SPEED);
	}
	
	//1, 4
	//左前/右后（向后）
	//2, 3
	//右前/左后（向前）
	for(int pwm_7 = 108, pwm_0 = 78, pwm_1 = 63, pwm_2 = 84, pwm_3 = 89, pwm_13 = 77, pwm_5 = 74, pwm_12 = 70, pwm_10 = 88, pwm_11 = 74 ; pwm_7 >= 88 ; pwm_7--)
	{
		if (pwm_0 <= 78) pwm_0++;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_2 >= 85) pwm_3--;
		if (pwm_13 <= 97) pwm_13++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_12 <= 85) pwm_12 += 2;
		if (pwm_10 >= 68) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(0, 0, PWM(pwm_0)); 
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (!avo)
		{
			if (dat != 0x61)
				return;
		}
		else
		{
			avdis = GetHcData();
			if (avdis <= 32)
				return;
			if (cou == 2)
			{
				u8 break_flag = 0;
				return;
			}
		}
		delay_ms(SPEED);
	}
}

void backup()
{
	setPWM(0, 0, PWM(80));
	setPWM(3, 0, PWM(87));
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	//1, 4
	//左前/右后（向前）94+6  108-94=14 74-63=11 83-74=9
	for(int pwm_7 = 82, pwm_1 = 83, pwm_2 = 84, pwm_13 = 97, pwm_5 = 74, pwm_12 = 72, pwm_10 = 76, pwm_11 = 80; pwm_7 <= 102; pwm_7++)
	{
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_13 >= 77) pwm_13--;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_12 <= 86) pwm_12 += 2;//94  80
		if (pwm_10 <= 94) pwm_10++;//74
		if (pwm_11 <= 92) pwm_11 += 2;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x62)
			return;
		delay_ms(SPEED + 30);
	}
	
	//1, 4
	//左前/右后（向后）
	//2, 3
	//右前/左后（向前）
	for(int pwm_7 = 102, pwm_1 = 63, pwm_2 = 68, pwm_13 = 77, pwm_5 = 86, pwm_12 = 86, pwm_10 = 94, pwm_11 = 92; pwm_7 >= 82; pwm_7--)
	{
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_13 <= 97) pwm_13++;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_12 >= 72) pwm_12 -= 2;
		if (pwm_10 >= 76) pwm_10--;
		if (pwm_11 >= 80) pwm_11 -= 2;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x62)
			return;
		delay_ms(SPEED + 30);
	}
}

void right()
{
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	for(int pwm_7 = 88, pwm_0 = 71, pwm_1 = 83, pwm_2 = 68, pwm_3 = 97, pwm_13 = 97, pwm_5 = 86, pwm_12 = 85, pwm_10 = 63, pwm_11 = 88 ; pwm_7 <= 108 ; pwm_7++)
	{
		if (pwm_0 <= 89) pwm_0++;
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_3 >= 77) pwm_3--;
		if (pwm_13 >= 77) pwm_13--;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_12 >= 70) pwm_12 -= 2;
		if (pwm_10 <= 83) pwm_10++;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x64)
			return;
		delay_ms(SPEED);
	}
	
	for(int pwm_7 = 108, pwm_0 = 89, pwm_1 = 63, pwm_2 = 84, pwm_3 = 77, pwm_13 = 77, pwm_5 = 74, pwm_12 = 70, pwm_10 = 83, pwm_11 = 70 ; pwm_7 >= 88 ; pwm_7--)
	{
		if (pwm_0 >= 71) pwm_0--;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_3 <= 97) pwm_3++;
		if (pwm_13 <= 97) pwm_13++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_12 <= 85) pwm_12 += 2;
		if (pwm_10 >= 63) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x64)
			return;
		delay_ms(SPEED);
	}
}

void left()
{
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	for (int pwm_7 = 88, pwm_0 = 89, pwm_1 = 83, pwm_2 = 74, pwm_3 = 77, pwm_13 = 99, pwm_5 = 86, pwm_12 = 85, pwm_10 = 63, pwm_11 = 88; pwm_7 <= 108; pwm_7++)
	{
		if (pwm_0 >= 71) pwm_0--;
		if (pwm_1 >= 60) pwm_1--;
		if (pwm_2 <= 86) pwm_2 += 2;
		if (pwm_3 <= 97) pwm_3++;
		if (pwm_13 >= 79) pwm_13--;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_12 >= 70) pwm_12 -= 2;
		if (pwm_10 <= 83) pwm_10++;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x63)
			return;
		delay_ms(SPEED + 2);
	}
	
	for (int pwm_7 = 108, pwm_0 = 71, pwm_1 = 60, pwm_2 = 86, pwm_3 = 97, pwm_13 = 79, pwm_5 = 74, pwm_12 = 70, pwm_10 = 83, pwm_11 = 70; pwm_7 >= 88; pwm_7--)
	{
		if (pwm_0 <= 89) pwm_0++;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 74) pwm_2 -= 2;
		if (pwm_3 >= 77) pwm_3--;
		if (pwm_13 <= 99) pwm_13++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_12 <= 85) pwm_12 += 2;
		if (pwm_10 >= 63) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		if (dat != 0x63)
			return;
		delay_ms(SPEED + 5);
	}
}

void moveleft()
{	
	setPWM(13, 0, PWM(87));
	setPWM(5, 0, PWM(80));
	
	setPWM(10, 0, PWM(78));
	setPWM(11, 0, PWM(74));	
	
	for (int pwm_0 = 70, pwm_1 = 83, pwm_2 = 88, pwm_3 = 96, pwm_6 = 88, pwm_7 = 86, pwm_12 = 80, pwm_9 = 79; pwm_6 >= 64; pwm_6--)
	{
		if (pwm_0 <= 87) pwm_0++;
		if (pwm_1 >= 73) pwm_1--;
		if (pwm_2 >= 78) pwm_2--;
		if (pwm_3 >= 78) pwm_3--;
		if (pwm_7 <= 100) pwm_7++;
		if (pwm_12 <= 93) pwm_12++;
		if (pwm_9 <= 97) pwm_9++;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		
		setPWM(6, 0, PWM(pwm_6));
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(9, 0, PWM(pwm_9));
		delay_ms(SPEED);
	}
	
	for (int pwm_0 = 87, pwm_1 = 73, pwm_2 = 78, pwm_3 = 78, pwm_6 = 64, pwm_7 = 100, pwm_12 = 93, pwm_9 = 97; pwm_6 <= 88; pwm_6++)
	{
		if (pwm_0 >= 70) pwm_0--;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 <= 88) pwm_2++;
		if (pwm_3 <= 96) pwm_3++;
		if (pwm_7 >= 86) pwm_7--;
		if (pwm_12 >= 80) pwm_12--;
		if (pwm_9 >= 79) pwm_9--;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		
		setPWM(6, 0, PWM(pwm_6));
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(9, 0, PWM(pwm_9));
		delay_ms(SPEED);
	}
}

void moveright()
{
	setPWM(1, 0, PWM(78));
	setPWM(2, 0, PWM(87));
	
	setPWM(7, 0, PWM(90));
	setPWM(12, 0, PWM(83));	
	
	for (int pwm_0 = 70, pwm_3 = 97, pwm_13 = 77, pwm_5 = 90, pwm_6 = 86, pwm_9 = 78, pwm_10 = 88, pwm_11 = 84; pwm_3 >= 77; pwm_3--)
	{
		if (pwm_0 <= 87) pwm_0++;
		if (pwm_13 <= 87) pwm_13++;
		if (pwm_5 >= 80) pwm_5--;
		if (pwm_6 >= 66) pwm_6--;
		if (pwm_9 <= 98) pwm_9++;
		if (pwm_10 >= 78) pwm_10--;
		if (pwm_11 >= 74) pwm_11--;
		
		setPWM(0, 0, PWM(pwm_0));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(6, 0, PWM(pwm_6));
		
		setPWM(9, 0, PWM(pwm_9));
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	
	for (int pwm_0 = 87, pwm_3 = 77, pwm_13 = 87, pwm_5 = 80, pwm_6 = 66, pwm_9 = 98, pwm_10 = 78, pwm_11 = 74; pwm_3 <= 97; pwm_3++)
	{
		if (pwm_0 >= 70) pwm_0--;
		if (pwm_13 >= 77) pwm_13--;
		if (pwm_5 <= 90) pwm_5++;
		if (pwm_6 <= 86) pwm_6++;
		if (pwm_9 >= 78) pwm_9--;
		if (pwm_10 <= 88) pwm_10++;
		if (pwm_11 <= 84) pwm_11++;
		
		setPWM(0, 0, PWM(pwm_0));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(6, 0, PWM(pwm_6));
		
		setPWM(9, 0, PWM(pwm_9));
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
}

void sitdowm()
{
	dowm();

	for (int pwm_2 = 94, pwm_1 = 94, pwm_13 = 72, pwm_5 = 90; pwm_2 >= 30; pwm_2--)
	{
		if (pwm_1 >= 50) pwm_1--;
		if (pwm_13 <= 106) pwm_13++;
		if (pwm_5 >= 40) pwm_5--;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
	
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		delay_ms(SPEED - 10);
	}
	
	setPWM(12, 0, PWM(125));
	setPWM(11, 0, PWM(44));
	delay_ms(1000);
	
	setPWM(7, 0, PWM(68));
	setPWM(10, 0, PWM(104));
	delay_ms(1000);
	
	setPWM(12, 0, PWM(90));
	setPWM(11, 0, PWM(74));
	delay_ms(1000);
	
	setPWM(1, 0, PWM(70));
	setPWM(13, 0, PWM(90));
	delay_ms(1000);
	
	for (int pwm_7 = 68, pwm_10 = 104; pwm_7 <= 120; pwm_7++)
	{
		if (pwm_10 >= 50) pwm_10--;
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(10, 0, PWM(pwm_10));
		delay_ms(SPEED);
	}
	delay_ms(1000);
	
	setPWM(1, 0, PWM(40));
	setPWM(3, 0, PWM(55));
	setPWM(13, 0, PWM(110));
	
	while (dat != 0x68)
	{
		for (int pwm_2 = 0, pwm_5 = 15; pwm_2 <= 50; pwm_2++) 
		{
			if (pwm_5 <= 60)pwm_5++;
		
			setPWM(2, 0, PWM(pwm_2));
			setPWM(5, 0, PWM(pwm_5));
			delay_ms(15);
		}
	
		for (int pwm_2 = 50, pwm_5 = 60; pwm_2 >= 0; pwm_2--) 
		{
			if (pwm_5 >= 15)pwm_5--;
		
			setPWM(2, 0, PWM(pwm_2));
			setPWM(5, 0, PWM(pwm_5));
			delay_ms(15);
		}
	}
	delay_ms(500);
	
	setPWM(1, 0, PWM(70));
	setPWM(2, 0, PWM(30));
	setPWM(3, 0, PWM(87));
	setPWM(13, 0, PWM(90));
	setPWM(5, 0, PWM(40));
	
	for (int pwm_7 = 120, pwm_10 = 50; pwm_7 >= 63; pwm_7--)
	{
		if (pwm_10 <= 104) pwm_10++;
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(10, 0, PWM(pwm_10));
		delay_ms(SPEED);
	}
	
	setPWM(1, 0, PWM(50));
	setPWM(13, 0, PWM(106));
	
	setPWM(12, 0, PWM(125));
	setPWM(11, 0, PWM(44));
	delay_ms(1000);
	
	setPWM(7, 0, PWM(108));
	setPWM(10, 0, PWM(68));
	delay_ms(700);
	
	for (int pwm_12 = 125, pwm_11 = 44; pwm_12 >= 87; pwm_12--)
	{
		if (pwm_11 <= 65) pwm_11++;
		setPWM(12, 0, PWM(pwm_12));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	delay_ms(300);
	
	for (int pwm_1 = 50, pwm_2 = 30, pwm_13 = 106, pwm_5 = 40, pwm_7 = 108, pwm_12 = 87, pwm_10 = 68, pwm_11 = 65; pwm_2 <= 78; pwm_2++)
	{
		if (pwm_1 <= 73) pwm_1++;
		if (pwm_13 >= 87) pwm_13--;
		if (pwm_5 <= 80) pwm_5++;
		if (pwm_7 >= 90) pwm_7--;
		if (pwm_12 >= 83) pwm_12--;
		if (pwm_10 <= 78) pwm_10++;
		if (pwm_11 <= 74) pwm_11++;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
	
		setPWM(13, 0, PWM(pwm_13));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(12, 0, PWM(pwm_12));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED - 10);
	}
}

void dowm()
{
	setPWM(0, 0, PWM(83));
	setPWM(1, 0, PWM(94));
	setPWM(2, 0, PWM(94));
	
	setPWM(3, 0, PWM(85));
	setPWM(13, 0, PWM(72));
	setPWM(5, 0, PWM(90));
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, PWM(108));
	setPWM(12, 0, PWM(95));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(64));
	setPWM(11, 0, PWM(58));
}

void avoidance(void)
{
	//delay_ms(1500);
	avo = 1;
	while (1) 
	{
		avdis = GetHcData();
		if (avdis == 1200)
		{
			for (u8 i = 0; i < 2; i++)
			{
				avdis = GetHcData();
				delay_us(100);
			}
		}
		
		if (avdis >= 30)
			forward();
	
		else if ((avdis >= 2) && (avdis < 30) && break_flag)
			avoidright();
		if (cou > 2)
			cou = 1;
		printf("cuo:%d\r\n", cou);
		if (cou == 2)
		{
			cou = 0;
			avo = 0;
			printf("%d\r\n", cou);
			goto ret;
		}
		
	}
ret:
	cou = 0;
	avo = 0;
	delay_ms(1000);
}

void avoidright()
{
	u8 count = 2;
	setPWM(1, 0, PWM(73));
	setPWM(2, 0, PWM(78));
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, PWM(90));
	setPWM(12, 0, PWM(83));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(78));
	setPWM(11, 0, PWM(74));	
	while (count--)
	{
		for (int pwm_0 = 70, pwm_3 = 97, pwm_13 = 77, pwm_5 = 90; pwm_3 >= 77; pwm_3--) 
		{
			if (pwm_0 <= 90) pwm_0++;
			if (pwm_13 <= 87) pwm_13++;
			if (pwm_5 >= 80) pwm_5--;
		
			setPWM(0, 0, PWM(pwm_0));
		
			setPWM(3, 0, PWM(pwm_3));
			setPWM(13, 0, PWM(pwm_13));
			setPWM(5, 0, PWM(pwm_5));
			/*if (dat != 0x69)
				return;*/
			delay_ms(SPEED + 5);
		}
	
		for (int pwm_0 = 90, pwm_3 = 77, pwm_13 = 87, pwm_5 = 80; pwm_3 <= 97; pwm_3++)
		{
			if (pwm_0 >= 70) pwm_0--;
			if (pwm_13 >= 77) pwm_13--;
			if (pwm_5 <= 90) pwm_5++;
		
			setPWM(0, 0, PWM(pwm_0));
		
			setPWM(3, 0, PWM(pwm_3));
			setPWM(13, 0, PWM(pwm_13));
			setPWM(5, 0, PWM(pwm_5));
			/*if (dat != 0x69)
				return;*/
			delay_ms(SPEED + 5);
		}
	}
}