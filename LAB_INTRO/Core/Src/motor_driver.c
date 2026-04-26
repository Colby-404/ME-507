#include "motor_driver.h"

void Motor_SetDuty(MotorDriver_t *m, int16_t duty)
{
    if (duty > 100) duty = 100;
    if (duty < -100) duty = -100;

    uint32_t compare = (uint32_t)((duty > 0 ? duty : -duty) * m->max_pwm / 100);

    if (duty > 0)
    {
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_forward, compare);
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_reverse, 0);
    }
    else if (duty < 0)
    {
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_forward, 0);
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_reverse, compare);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_forward, 0);
        __HAL_TIM_SET_COMPARE(m->htim, m->ch_reverse, 0);
    }
}

void Motor_Enable(MotorDriver_t *m)
{
    HAL_TIM_PWM_Start(m->htim, m->ch_forward);
    HAL_TIM_PWM_Start(m->htim, m->ch_reverse);
}

void Motor_Disable(MotorDriver_t *m)
{
    HAL_TIM_PWM_Stop(m->htim, m->ch_forward);
    HAL_TIM_PWM_Stop(m->htim, m->ch_reverse);
}
