/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BLE_SWITCH_Pin GPIO_PIN_10
#define BLE_SWITCH_GPIO_Port GPIOF
#define BLE_WKP_Pin GPIO_PIN_2
#define BLE_WKP_GPIO_Port GPIOC
#define BLE_RST_Pin GPIO_PIN_3
#define BLE_RST_GPIO_Port GPIOC
#define GPS_RES_Pin GPIO_PIN_1
#define GPS_RES_GPIO_Port GPIOB
#define GPS_INT_Pin GPIO_PIN_2
#define GPS_INT_GPIO_Port GPIOB
#define GPS_SWITCH_Pin GPIO_PIN_11
#define GPS_SWITCH_GPIO_Port GPIOF
#define On_Buz_Pin GPIO_PIN_12
#define On_Buz_GPIO_Port GPIOF
#define CHARGE_INT_Pin GPIO_PIN_13
#define CHARGE_INT_GPIO_Port GPIOF
#define CHARGE_INT_EXTI_IRQn EXTI15_10_IRQn
#define ACCEL_INT_Pin GPIO_PIN_9
#define ACCEL_INT_GPIO_Port GPIOE
#define LCD_SPI_DCX_Pin GPIO_PIN_10
#define LCD_SPI_DCX_GPIO_Port GPIOE
#define LCD_DSI_TE_Pin GPIO_PIN_11
#define LCD_DSI_TE_GPIO_Port GPIOE
#define LCD_VCI_EN_Pin GPIO_PIN_12
#define LCD_VCI_EN_GPIO_Port GPIOE
#define LCD_RES_Pin GPIO_PIN_13
#define LCD_RES_GPIO_Port GPIOE
#define LCD_SWITCH_Pin GPIO_PIN_14
#define LCD_SWITCH_GPIO_Port GPIOE
#define Enter_Button_Pin GPIO_PIN_10
#define Enter_Button_GPIO_Port GPIOD
#define Enter_Button_EXTI_IRQn EXTI15_10_IRQn
#define DOWN_Pin GPIO_PIN_12
#define DOWN_GPIO_Port GPIOD
#define DOWN_EXTI_IRQn EXTI15_10_IRQn
#define SENSORS_LDO_Pin GPIO_PIN_14
#define SENSORS_LDO_GPIO_Port GPIOD
#define LCD_LDO_EN_Pin GPIO_PIN_15
#define LCD_LDO_EN_GPIO_Port GPIOD
#define LCD_PWM_Pin GPIO_PIN_9
#define LCD_PWM_GPIO_Port GPIOC
#define PD0_Pin GPIO_PIN_0
#define PD0_GPIO_Port GPIOD
#define PD1_Pin GPIO_PIN_1
#define PD1_GPIO_Port GPIOD
#define PD4_Pin GPIO_PIN_4
#define PD4_GPIO_Port GPIOD
#define GSM_BUCK_PG_Pin GPIO_PIN_5
#define GSM_BUCK_PG_GPIO_Port GPIOD
#define GSM_INT_Pin GPIO_PIN_11
#define GSM_INT_GPIO_Port GPIOG
#define GSM_INT_EXTI_IRQn EXTI15_10_IRQn
#define GSM_PW_KEY_Pin GPIO_PIN_12
#define GSM_PW_KEY_GPIO_Port GPIOG
#define GSM_BUCK_EN_Pin GPIO_PIN_15
#define GSM_BUCK_EN_GPIO_Port GPIOG
#define HUB_RST_Pin GPIO_PIN_4
#define HUB_RST_GPIO_Port GPIOB
#define BOOT0_Pin GPIO_PIN_3
#define BOOT0_GPIO_Port GPIOH
#define HUB_SYSTEM_SWITCH_Pin GPIO_PIN_8
#define HUB_SYSTEM_SWITCH_GPIO_Port GPIOB
#define ON_HRV_Pin GPIO_PIN_9
#define ON_HRV_GPIO_Port GPIOB
#define HRV_INT_Pin GPIO_PIN_0
#define HRV_INT_GPIO_Port GPIOE
#define HRV_ALLERT_Pin GPIO_PIN_1
#define HRV_ALLERT_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
