/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define BUFFER_LENGTH 64

extern int current_buffer_length_uart2;
extern uint8_t single_buffer_uart2;
extern uint8_t read_buffer_uart2[BUFFER_LENGTH + 1];

extern int current_buffer_length_uart3;
extern uint8_t single_buffer_uart3;
extern uint8_t read_buffer_uart3[BUFFER_LENGTH + 1];

extern int32_t steer;
extern int32_t speed;
extern int32_t timeout_count;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_FREQUENCE 50
#define APB2_TIMER_CLOCK 72000000
#define APB1_TIMER_CLOCK 72000000
#define PWM_DEFAULT_DUTY 2000
#define TIM_PSC_APB1 72
#define PWM_RESOLUTION 20000
#define TIM_PSC_APB2 72
/* USER CODE BEGIN Private defines */
#define TIMEOUT 100
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
