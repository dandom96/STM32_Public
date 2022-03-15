/*
 * I2C_Temp.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Dominik
 */
#include "i2c_temp.h"
//------------------------------------------------
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart2;
extern char str1[100];
//------------------------------------------------
void Error(void)
{
  LED_OFF;
}
//------------------------------------------------
void SHT31_Init(void)
{
  uint8_t value=0;
  uint32_t value32=0;
  LED_ON;
}
//------------------------------------------------
static void I2Cx_WriteData(uint16_t Addr, uint8_t Reg, uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_I2C_Mem_Write(&hi2c1, Addr, (uint16_t)Reg, I2C_MEMADD_SIZE_8BIT, &Value, 1, 0x10000);
  if(status != HAL_OK) Error();
}
//------------------------------------------------
static uint8_t I2Cx_ReadData(uint16_t Addr, uint8_t Reg)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t value = 0;
  status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, &value, 1, 0x10000);
  if(status != HAL_OK) Error();
  return value;
}
//------------------------------------------------
static void I2Cx_ReadData16(uint16_t Addr, uint8_t Reg, uint16_t *Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)Value, 2, 0x10000);
  if(status != HAL_OK) Error();
}
//------------------------------------------------
static void I2Cx_ReadData24(uint16_t Addr, uint8_t Reg, uint32_t *Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_I2C_Mem_Read(&hi2c1, Addr, Reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)Value, 3, 0x10000);
  if(status != HAL_OK) Error();
}
//------------------------------------------------
void SHT31_WriteReg(uint8_t Reg, uint8_t Value)
{
  I2Cx_WriteData(SHT31_ADDRESS, Reg, Value);
}
//------------------------------------------------
uint8_t SHT31_ReadReg(uint8_t Reg)
{
  uint8_t res = I2Cx_ReadData(SHT31_ADDRESS,Reg);
  return res;
}
//------------------------------------------------
