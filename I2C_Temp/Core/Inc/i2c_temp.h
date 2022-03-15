/*
 * i2c_temp.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Dominik
 */

#ifndef INC_I2C_TEMP_H_
#define INC_I2C_TEMP_H_
//-------------------------------
#include "stm32f4xx_hal.h"
#include <string.h>
#include <math.h>
//------------------------------------------------
#define LED_GPIO_PORT GPIOA
#define LED_PIN GPIO_PIN_5
#define LED_ON HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET)
#define LED_OFF HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET)
#define LED_TGL HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN)
//------------------------------------------------
#define SHT31_ADDRESS 0x88  //SHT31 I2C ADDRES (0x44<<1)
void SHT31_Init(void);
//-------------------------------
#endif /* INC_I2C_TEMP_H_ */
