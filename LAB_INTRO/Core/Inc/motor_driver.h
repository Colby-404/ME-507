#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "main.h"
#include <stdint.h>

typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t ch_forward;
    uint32_t ch_reverse;
    uint32_t max_pwm;
} MotorDriver_t;

void Motor_SetDuty(MotorDriver_t *m, int16_t duty);
void Motor_Enable(MotorDriver_t *m);
void Motor_Disable(MotorDriver_t *m);

#endif
