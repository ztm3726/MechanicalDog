#ifndef __RUN_H
#define __RUN_H
#include "pca9685.h"
#include "delay.h"

#define PWM(n)  (int)(204.8 * (0.5 + n * 1.0 / 90))
#define SPEED 20

void motionless(void);
void forward(void);
void backup(void);
void left(void);
void right(void);
void dowm();


#endif

