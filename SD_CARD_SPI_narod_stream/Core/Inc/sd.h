/*
 * sd.h
 *
 *  Created on: Dec 13, 2021
 *      Author: Daniil
 */

#ifndef INC_SD_H_
#define INC_SD_H_

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define CS_SD_GPIO_PORT GPIOB
#define CS_SD_PIN GPIO_PIN_2
#define SS_SD_SELECT() HAL_GPIO_WritePin(CS_SD_GPIO_PORT, CS_SD_PIN, GPIO_PIN_RESET)
#define SS_SD_DESELECT() HAL_GPIO_WritePin(CS_SD_GPIO_PORT, CS_SD_PIN, GPIO_PIN_SET)
#define LD_ON HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)
#define LD_OFF HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET)

//Card type flags
#define CT_MMC 0x01   //MMC ver.3
#define CT_SD1 0x02    //SD ver.1
#define CT_SD2 0x04    //SD ver.2
#define CT_SDC (CT_SD1|SC_SD2)   //SD
#define CT_BLOCK 0x08

typedef struct sd_info
{
	volatile uint8_t type;     // SD Card Type
} sd_info_ptr;

void SD_PowerOn(void);
uint8_t sd_init(void);
void SPI_Release(void);

#endif /* INC_SD_H_ */
