//
// Created by xie on 2025/9/20.
//

#ifndef MOTOR_2312_MOTOR_SET_H
#define MOTOR_2312_MOTOR_SET_H

#include "tim.h"

// Motor config
// If use defferent voltage motor,please change these parameters
#define V_MAX 17.4f
#define KV 800.0f
#define RPM_MAX (KV * V_MAX)
#define PWM_FREQ 400
#define D_MIN 0.40f
#define D_MAX 0.90f
#define PSC 167
#define ARR 2499

/// @brief  Send pulse to motor to control speed
/// @param htim TIMx
/// @param Channel
/// @param pulse target pulse width
void Motor_SendPulse(TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t pulse);

/// @brief Set motor throttle percentage (0-100%)
void Motor_SetThrottle(TIM_HandleTypeDef *htim, uint32_t channel, float throttle_percent);

/// @brief Set rpm (0-RPM_MAX)
void Motor_SetRPM(TIM_HandleTypeDef *htim, uint32_t channel, float rpm);
#endif // MOTOR_2312_MOTOR_SET_H
