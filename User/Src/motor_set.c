//
// Created by xie on 2025/9/20.
//
#include "motor_set.h"

#include <stdio.h>

void Motor_SendPulse(TIM_HandleTypeDef *htim, uint32_t Channel, uint16_t pulse) {
    __HAL_TIM_SET_COMPARE(htim, Channel, pulse);
}

void Motor_SetThrottle(TIM_HandleTypeDef *htim, uint32_t channel, float throttle_percent) {
    if (throttle_percent < 0) {
        throttle_percent = 0;
        printf("Throttle percent cannot be less than 0%%. Set to 0%%.\r\n");
    }
    if (throttle_percent > 100) {
        throttle_percent = 100;
        printf("Throttle percent cannot be more than 100%%. Set to 100%%.\r\n");
    }

    float D_pwm = D_MIN + (D_MAX - D_MIN) * (throttle_percent / 100.0f);
    uint32_t pulse = (uint32_t) (D_pwm * (ARR + 1));
    Motor_SendPulse(htim, channel, pulse);
}

void Motor_SetRPM(TIM_HandleTypeDef *htim, uint32_t channel, float rpm) {
    if (rpm < 0) {
        rpm = 0;
        printf("RPM cannot be less than 0. Set to 0.\r\n");
    }
    if (rpm > RPM_MAX) {
        rpm = RPM_MAX;
        printf("RPM cannot be more than %.2f. Set to %.2f.\r\n", RPM_MAX, RPM_MAX);
    }

    float throttle_percent = (rpm / RPM_MAX) * 100.0f;
    Motor_SetThrottle(htim, channel, throttle_percent);
}

void ESC_Calibrate(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t calibrate) {
    Motor_Init();
    if (calibrate) {
        // Set max throttle (2000 µs)
        Motor_SendPulse(htim, channel, (uint32_t) (D_MAX * (ARR + 1)));
        HAL_Delay(ESC_CALIB_DELAY);

        // Set min throttle (1000 µs)
        Motor_SendPulse(htim, channel, (uint32_t) (D_MIN * (ARR + 1)));
        HAL_Delay(ESC_CALIB_DELAY);
    }
}
