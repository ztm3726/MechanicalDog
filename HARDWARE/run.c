#include "run.h"

void motionless()
{
	u16 pwm = calculate_PWM(80);
	
	setPWM(0, 0, PWM(83));
	setPWM(1, 0, PWM(73));
	setPWM(2, 0, PWM(78));
	
	setPWM(3, 0, PWM(85));
	setPWM(4, 0, PWM(87));
	setPWM(5, 0, pwm);
	
	setPWM(6, 0, PWM(76));
	setPWM(7, 0, pwm);
	setPWM(8, 0, PWM(70));
	
	setPWM(9, 0, PWM(88));
	setPWM(10, 0, PWM(91));
	setPWM(11, 0, PWM(86));
}

void forward()
{
	setPWM(0, 0, PWM(80));
	setPWM(3, 0, PWM(87));
	setPWM(6, 0, PWM(76));
	setPWM(9, 0, PWM(88));

	//25
	//1, 4
	//左前/右后（向前）
	for(int pwm_7 = 74, pwm_1 = 83, pwm_2 = 68, pwm_4 = 97, pwm_5 = 86, pwm_8 = 75, pwm_10 = 80, pwm_11 = 100 ; pwm_7 <= 94; pwm_7++)
	{
		if (pwm_1 >= 63) pwm_1--;
		if (pwm_2 <= 84) pwm_2 += 2;
		if (pwm_4 >= 77) pwm_4 --;
		if (pwm_5 >= 74) pwm_5 -=2;
		if (pwm_8 >= 60) pwm_8 -= 2;
		if (pwm_10 <= 100) pwm_10++;
		if (pwm_11 >= 82) pwm_11 -= 2;
		
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
	
	//35
	//1, 4
	//左前/右后（向后）
	//2, 3
	//右前/左后（向前）
	for(int pwm_7 = 94, pwm_1 = 63, pwm_2 = 84, pwm_4 = 77, pwm_5 = 74, pwm_8 = 60, pwm_10 = 100, pwm_11 = 82; pwm_7 >= 74 ; pwm_7--)
	{
		if (pwm_1 <= 83) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_4 <= 97) pwm_4++;
		if (pwm_5 <= 86) pwm_5 += 2;
		if (pwm_8 <= 75) pwm_8 += 2;
		if (pwm_10 >= 80) pwm_10--;
		if (pwm_11 <= 100) pwm_11 += 2;
		
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
	
	//30
	/*for (int pwm_10 = 100, pwm_1 = 60, pwm_2 = 88, pwm_11 = 66; pwm_10 >= 70; pwm_10--)
	{
		if (pwm_1 <= 90) pwm_1++;
		if (pwm_2 >= 68) pwm_2 -= 2;
		if (pwm_11 <= 96) pwm_11 += 2;
		setPWM(1, 0, PWM(pwm_1));
		setPWM(2, 0, PWM(pwm_2));
		setPWM(10, 0, PWM(pwm_10));
		setPWM(11, 0, PWM(pwm_11));
		delay_ms(60);
	}*/
	
	//35
	//2, 4
	//右前/左后（向后）
	/*for (int pwm_7 = 65, pwm_8 = 90, pwm_4 = 100, pwm_5 = 75; pwm_7 <= 100; pwm_7++)
	{
		if (pwm_4 >= 70) pwm_4--;
		if (pwm_5 <= 100) pwm_5++;
		if (pwm_8 >= 70) pwm_8--;
		setPWM(4, 0, PWM(pwm_4));
		setPWM(5, 0, PWM(pwm_5));
		setPWM(7, 0, PWM(pwm_7));
		setPWM(8, 0, PWM(pwm_8));
		delay_ms(60);
	}*/
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