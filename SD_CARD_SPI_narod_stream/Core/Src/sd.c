/*
 * sd.c
 *
 *  Created on: Dec 13, 2021
 *      Author: Daniil
 */

#include "sd.h"

extern volatile uint16_t Timer1;
sd_info_ptr sdinfo;

// Подключаем Хэндлы шин
extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart2;

// Функция ыключения зеленого светодиода в случае ошибки
static void Error (void)
{
	LD_ON;
}

// Функция для записи и чтения SPI
uint8_t SPIx_WriteRead(uint8_t Byte)
{
	uint8_t receivedbyte = 0;
	if (HAL_SPI_TransmitReceive(&hspi2, (uint8_t*) &Byte, (uint8_t*) &receivedbyte,1,0x1000) != HAL_OK)
	{
		Error();
	}
	return receivedbyte;
}

//Send Byte
void SPI_SendByte(uint8_t bt)
{
	SPIx_WriteRead(bt);
}

//Receive Byte
uint8_t SPI_ReceiveByte(void)
{
	uint8_t bt = SPIx_WriteRead(0xFF);
	return bt;
}

// Release
void SPI_Release(void)
{
	SPIx_WriteRead(0xFF);
}

//Функция ожидания стабилихации питания SD карты
void SD_PowerOn(void)
{
	Timer1 = 0;
	while(Timer1 < 2) //Ждем 200 милисекунд
	{

	}
}

// Функция инициализации SD карты

uint8_t sd_init(void)
{
	uint8_t i;
	int16_t tmr;
	uint32_t temp;
	LD_OFF;
	sdinfo.type = 0;
	return 0;
}

