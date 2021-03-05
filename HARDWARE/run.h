#ifndef __RUN_H
#define __RUN_H
#include <stdio.h>
#include "pca9685.h"
#include "delay.h"
#include "wifi.h"
#include "hcsr04.h"

#define PWM(n)  (int)(204.8 * (0.5 + n * 1.0 / 90))
#define SPEED 15

void motionless(void);
void forward(void);
void backup(void);
void left(void);
void right(void);
void moveleft(void);
void moveright(void);
void sitdowm(void);
void avoidance(void);
void avoidright(void);
void dowm();

#endif