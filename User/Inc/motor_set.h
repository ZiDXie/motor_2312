//
// Created by xie on 2025/9/20.
//

#ifndef MOTOR_2312_MOTOR_SET_H
#define MOTOR_2312_MOTOR_SET_H

#include "stdio.h"
#include "tim.h"

// Motor config
// If use defferent voltage motor,please change these parameters
#define V_MAX 17.4f
#define KV 800.0f
#define RPM_MAX (KV * V_MAX)
#define PWM_FREQ 400
#define D_MIN 0.40f
#define D_MAX 0.80f
#define PSC 167
#define ARR 2499
#define MOTOR_DELAY 500
#define ESC_CALIB_DELAY 2000

/// @brief Initialize the motor by starting PWM on TIM1 Channel 1 and adding a delay.
/// TIM1 Channel 1 is used to control the motor speed.
/// Motor init pwm pulse is set to 1000
void Motor_Init() {
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_Delay(MOTOR_DELAY);
    printf("Motor init success\r\n");
}

/// @brief  Send pulse to motor to control speed
/// @param htim TIMx
/// @param Channel
/// @param pulse target pulse width
void Motor_SendPulse(TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t pulse);

/// @brief Set motor throttle percentage (0-100%)
void Motor_SetThrottle(TIM_HandleTypeDef *htim, uint32_t channel, float throttle_percent);

/// @brief Set rpm (0-RPM_MAX)
void Motor_SetRPM(TIM_HandleTypeDef *htim, uint32_t channel, float rpm);

/// @brief Calibrate the ESC (Electronic Speed Controller)
/// This function sends a maximum and minimal throttle signal to the ESC for calibration.
/// @param calibrate set to 1 to start calibration, 0 to disable calibration
void ESC_Calibrate(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t calibrate);

#endif // MOTOR_2312_MOTOR_SET_H
