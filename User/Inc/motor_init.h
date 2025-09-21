//
// Created by xie on 2025/9/20.
//

#ifndef MOTOR_2312_MOTOR_INIT_H
#define MOTOR_2312_MOTOR_INIT_H

#include "stdio.h"
#include "tim.h"

#define MOTOR_DELAY 500

/// @brief Initialize the motor by starting PWM on TIM1 Channel 1 and adding a delay.
/// TIM1 Channel 1 is used to control the motor speed.
/// Motor init pwm pulse is set to 1000
void Motor_Init() {
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_Delay(MOTOR_DELAY);
    printf("Motor init success\r\n");
}
#endif // MOTOR_2312_MOTOR_INIT_H
