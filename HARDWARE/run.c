#include "run.h"

void motionless()
{
	setPWM(0, 0, PWM(80));
	setPWM(1, 0, PWM(73));
	setPWM(2, 0, PWM(78));
	
	setPWM(3, 0, PWM(87));
	setPWM(4, 0, PWM(87));
	setPWM(5, 0, PWM(80));
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, PWM(94));
	setPWM(8, 0, PWM(80));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(74));
	setPWM(11, 0, PWM(74));	
}

void forward()
{
	setPWM(0, 0, PWM(80));
	setPWM(3, 0, PWM(87));
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	//1, 4
	//左前/右后（向前）
	/*setPWM(7, 0, PWM(80));
	setPWM(8, 0, PWM(70));
	
	setPWM(10, 0, PWM(91));
	setPWM(11, 0, PWM(86));*/
	for(int pwm_7 = 88, pwm_1 = 83, pwm_2 = 68, pwm_4 = 97, pwm_5 = 86, pwm_8 = 85, pwm_10 = 63, pwm_11 = 88 ; pwm_7 <= 108; pwm_7++)
	{
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_4 >= 77) pwm_4 --;
		if (pwm_5 >= 74) pwm_5 -=2;
		if (pwm_8 >= 70) pwm_8 -= 2;
		if (pwm_10 <= 83) pwm_10++;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(1, 0, PWM(pwm_1)); 
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	
	//1, 4
	//左前/右后（向后）
	//2, 3
	//右前/左后（向前）
	for(int pwm_7 = 108, pwm_1 = 63, pwm_2 = 84, pwm_4 = 77, pwm_5 = 74, pwm_8 = 70, pwm_10 = 83, pwm_11 = 70 ; pwm_7 >= 88 ; pwm_7--)
	{
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_4 <= 97) pwm_4++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_8 <= 85) pwm_8 += 2;
		if (pwm_10 >= 63) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
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
	for(int pwm_7 = 80, pwm_1 = 83, pwm_2 = 84, pwm_4 = 97, pwm_5 = 74, pwm_8 = 70, pwm_10 = 65, pwm_11 = 70 ; pwm_7 <= 100; pwm_7++)
	{
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_4 >= 77) pwm_4--;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_8 <= 85) pwm_8 += 2;
		if (pwm_10 <= 81) pwm_10++;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	
	//1, 4
	//左前/右后（向后）
	//2, 3
	//右前/左后（向前）
	for(int pwm_7 = 100, pwm_1 = 63, pwm_2 = 68, pwm_4 = 77, pwm_5 = 86, pwm_8 = 85, pwm_10 = 81, pwm_11 = 88 ; pwm_7 >= 80; pwm_7--)
	{
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_4 <= 97) pwm_4++;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_8 >= 70) pwm_8 -= 2;
		if (pwm_10 >= 65) pwm_10--;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
}

void right()
{
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	for(int pwm_7 = 88, pwm_0 = 72, pwm_1 = 83, pwm_2 = 68, pwm_3 = 98, pwm_4 = 97, pwm_5 = 86, pwm_8 = 85, pwm_10 = 63, pwm_11 = 88 ; pwm_7 <= 108 ; pwm_7++)
	{
		if (pwm_0 <= 88) pwm_0++;
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_3 >= 79) pwm_3--;
		if (pwm_4 >= 77) pwm_4--;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_8 >= 70) pwm_8 -= 2;
		if (pwm_10 <= 83) pwm_10++;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	
	for(int pwm_7 = 108, pwm_0 = 88, pwm_1 = 63, pwm_2 = 84, pwm_3 = 79, pwm_4 = 77, pwm_5 = 74, pwm_8 = 70, pwm_10 = 83, pwm_11 = 70 ; pwm_7 >= 88 ; pwm_7--)
	{
		if (pwm_0 >= 72) pwm_0--;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_3 <= 98) pwm_3++;
		if (pwm_4 <= 97) pwm_4++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_8 <= 85) pwm_8 += 2;
		if (pwm_10 >= 63) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
}

void left()
{
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	for (int pwm_7 = 88, pwm_0 = 88, pwm_1 = 83, pwm_2 = 68, pwm_3 = 79, pwm_4 = 97, pwm_5 = 86, pwm_8 = 85, pwm_10 = 63, pwm_11 = 88; pwm_7 <= 108; pwm_7++)
	{
		if (pwm_0 >= 69) pwm_0--;
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_3 <= 95) pwm_3++;
		if (pwm_4 >= 77) pwm_4--;
		if (pwm_5 >= 74) pwm_5 -= 2;
		if (pwm_8 >= 70) pwm_8 -= 2;
		if (pwm_10 <= 83) pwm_10++;
		if (pwm_11 >= 70) pwm_11 -= 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
	
	for (int pwm_7 = 108, pwm_0 = 69, pwm_1 = 63, pwm_2 = 84, pwm_3 = 95, pwm_4 = 77, pwm_5 = 74, pwm_8 = 70, pwm_10 = 83, pwm_11 = 70; pwm_7 >= 88; pwm_7--)
	{
		if (pwm_0 <= 88) pwm_0++;
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_3 >= 79) pwm_3--;
		if (pwm_4 <= 97) pwm_4++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_8 <= 85) pwm_8 += 2;
		if (pwm_10 >= 63) pwm_10--;
		if (pwm_11 <= 88) pwm_11 += 2;
		
		setPWM(0, 0, PWM(pwm_0));
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		
		setPWM(3, 0, PWM(pwm_3));
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(SPEED);
	}
}

void dowm()
{
	u16 pwm = calculate_PWM(80);
	
	setPWM(0, 0, PWM(83));
	setPWM(1, 0, PWM(94));
	setPWM(2, 0, PWM(88));
	
	setPWM(3, 0, PWM(85));
	setPWM(4, 0, PWM(66));
	setPWM(5, 0, PWM(88));
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, PWM(108));
	setPWM(8, 0, PWM(88));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(64));
	setPWM(11, 0, PWM(70));
}