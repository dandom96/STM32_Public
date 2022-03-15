/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t sw[1] = "0";
uint8_t buf[6];
uint8_t buf_GPS[1020]={0};
RTC_TimeTypeDef sTime = {0};
RTC_DateTypeDef sDate = {0};
//char trans_str[] = {0};
//uint8_t buf_GPS2[255]={0};
//uint8_t mes_hum[] = "Enter 1 to get humidity data\r\n";
//uint8_t mes_temp[] = "Enter 2 to get temperature data\r\n";
//uint8_t mes_en_heat[] = "Enter 3 to Enable Heater\r\n";
//uint8_t mes_dis_heat[] = "Enter 4 to Disable Heater\r\n";
//uint8_t mes_gps[] = "Enter 5 to Get GPS Data\r\n\n";
//uint8_t Err = 0;
//uint8_t check[6];
float hum;
float temp;
HAL_StatusTypeDef ret;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */
uint8_t con_test ();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//Connection Test Function
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	  HAL_UART_Receive_IT(&huart2, sw, 1);
	  if(sw[0]=='1')
	  		  {
	  	  	  		  //Temperature and Humidity Receive
		  	  	  	  sw[0] = '0';
	  	  	  		  buf[0] = (uint8_t)(READ_TEMP_REG >> 8);
	  	  	  		  buf[1] = (uint8_t)READ_TEMP_REG;
	  	  	  		  ret = HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
	  	  	  		  if (ret != HAL_OK)
	  	  	  		  {
			  			  printf("Sensor connection ERROR\r\n\n");
	  	  	  		  }
	  	  	  		  else
	  	  	  		  {
	  	  	  			  HAL_I2C_Master_Receive(&hi2c1, SHT_ADDR, buf, 6, 100);

	  	  	  			  hum = humidity(buf);

	  	  	  		  printf("Humidity is %.2f %%\r\n", hum);
	  	  	  		  printf("Enter 1 to get humidity data\r\n");
	  	  	  		  printf("Enter 2 to get temperature data\r\n");
	  	  	  		  printf("Enter 3 to Enable Heater\r\n");
	  	  	  		  printf("Enter 4 to Disable Heater\r\n");
	  	  	  		  printf("Enter 5 to Get GPS Data\r\n\n");
	  	  	  		  }
	  		  }

	  if(sw[0]=='2')
	  		  {
	  	  	          sw[0] = '0';
	  	  	  		  //Temperature and Humidity Receive
	  	  	  		  buf[0] = (uint8_t)(READ_TEMP_REG >> 8);
	  	  	  		  buf[1] = (uint8_t)READ_TEMP_REG;
	  	  	  		  ret = HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
	  	  	  		  if (ret != HAL_OK)
	  	  	  		  {
			  			  printf("Sensor connection ERROR\r\n\n");
	  	  	  		  }
	  	  	  		  else
	  	  	  		  {
	  	  	  			  HAL_I2C_Master_Receive(&hi2c1, SHT_ADDR, buf, 6, 100);

	  	  	  			  temp = temperature(buf);

	  	  	  		  printf("Temperature is %.2f C\r\n", temp);
	  	  	  		  printf("Enter 1 to get humidity data\r\n");
	  	  	  		  printf("Enter 2 to get temperature data\r\n");
	  	  	  		  printf("Enter 3 to Enable Heater\r\n");
	  	  	  		  printf("Enter 4 to Disable Heater\r\n");
	  	  	  		  printf("Enter 5 to Get GPS Data\r\n\n");
	  	  	  		  }
	  		  }
	  if(sw[0]=='3')
	  		  {
	          	  	  sw[0] = '0';
	  	  	  		  //Heater Enable
	  	  	  		  buf[0] = (uint8_t)(HEATER_EN_REG >> 8);
	  	  	  		  buf[1] = (uint8_t)HEATER_EN_REG;
	  	  	  		  ret = HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
	  	  	  		  if (ret != HAL_OK)
	  	  	  		  {
			  			  printf("Sensor connection ERROR\r\n\n");
	  	  	  		  }
	  	  	  		  else
	  	  	  		  {
	  	  	  		  printf("The Heater is Enabled\r\n");
	  	  	  		  printf("Enter 1 to get humidity data\r\n");
	  	  	  		  printf("Enter 2 to get temperature data\r\n");
	  	  	  		  printf("Enter 3 to Enable Heater\r\n");
	  	  	  		  printf("Enter 4 to Disable Heater\r\n");
	  	  	  		  printf("Enter 5 to Get GPS Data\r\n\n");
	  	  	  		  }
	  		  }
	  if(sw[0]=='4')
	  		  {
		  	  	  	  sw[0] = '0';
	  	  	  		  //Heater Enable
	  	  	  		  buf[0] = (uint8_t)(HEATER_DIS_REG >> 8);
	  	  	  		  buf[1] = (uint8_t)HEATER_DIS_REG;
	  	  	  		  ret = HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
	  	  	  		  if (ret != HAL_OK)
	  	  	  		  {
			  			  printf("Sensor connection ERROR\r\n\n");
	  	  	  		  }
	  	  	  		  else
	  	  	  		  {
	  	  	  		  printf("The Heater is Disabled\r\n");
	  	  	  		  printf("Enter 1 to get humidity data\r\n");
	  	  	  		  printf("Enter 2 to get temperature data\r\n");
	  	  	  		  printf("Enter 3 to Enable Heater\r\n");
	  	  	  		  printf("Enter 4 to Disable Heater\r\n");
	  	  	  		  printf("Enter 5 to Get GPS Data\r\n\n");

	  	  	  		  }
	  		  }
	  if(sw[0]=='5')
	  		  {
	  	  	  	  	  sw[0] = '0';
	  	  	  		//Get GPS data
	  	  	  	  	  //HAL_UART_Receive(&huart1, buf_GPS, 255, 1000);
	  	  	  	  	  HAL_UART_Receive(&huart1, buf_GPS, 1020, HAL_MAX_DELAY);
		  	  	  	  printf("The GPS Data is\r\n");
		  	  	  	  //printf("%s\r\n", buf_GPS);
		  	  	      HAL_UART_Transmit(&huart2, buf_GPS, 1020, HAL_MAX_DELAY);
		  	  	     // printf("\r\n");
  	  	  			  //printf("The Heater is Disabled\r\n");
	  	  	  		  printf("\r\nEnter 1 to get humidity data\r\n");
	  	  	  		  printf("Enter 2 to get temperature data\r\n");
	  	  	  		  printf("Enter 3 to Enable Heater\r\n");
	  	  	  		  printf("Enter 4 to Disable Heater\r\n");
	  	  	  		  printf("Enter 5 to Get GPS Data\r\n\n");
	  	  	  		  //HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	  	  	  		 // printf("Time %d:%d:%d\n\r", sTime.Hours, sTime.Minutes, sTime.Seconds);
	  		  }
		  else
		  {
		    __NOP();
		  }
}

//Function for printf
int _write(int file, char *ptr, int len)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, 1000);
	return len;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
 //TIM2 Start
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);
  //Get Status;
  buf[0] = (uint8_t)(SHT_STAT_REG >> 8);
  buf[1] = (uint8_t)SHT_STAT_REG;
  //ret = HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
  //if (ret != HAL_OK)
  //{
	//  printf("Sensor connection ERROR\r\n\n");
  //}
  //else
  //{
	  HAL_I2C_Master_Receive(&hi2c1, SHT_ADDR, buf, 3, 100);
	  //Err = con_test();

  //Start Measurement command
	  buf[0] = (uint8_t)(MES_CMD_REG >> 8);
	  buf[1] = (uint8_t)MES_CMD_REG;
	  HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);

	  printf("Enter 1 to get humidity data\r\n");
	  printf("Enter 2 to get temperature data\r\n");
	  printf("Enter 3 to Enable Heater\r\n");
	  printf("Enter 4 to Disable Heater\r\n");
	  printf("Enter 5 to Get GPS Data\r\n\n");
	  //HAL_UART_Transmit(&huart2, mes_hum, sizeof(mes_hum),100);
	  //HAL_UART_Transmit(&huart2, mes_temp, sizeof(mes_temp),100);
	  //HAL_UART_Transmit(&huart2, mes_en_heat, sizeof(mes_en_heat),100);
	  //HAL_UART_Transmit(&huart2, mes_dis_heat, sizeof(mes_dis_heat),100);
	  //HAL_UART_Transmit(&huart2, mes_gps, sizeof(mes_gps),100);

	  //Uart Receive command
	  HAL_UART_Receive_IT(&huart2, sw, 1);
//  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //HAL_UART_Receive(&huart1, buf_GPS, 1020, HAL_MAX_DELAY);
	  //for (int i=0; i<255; i++)
	  //{
		// buf_GPS2[i] = buf_GPS[i];
	  //}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  //HAL_Delay(250);
	  //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);

	  //Temperature and Humidity Receive
	  /*
	  buf[0] = (uint8_t)(READ_TEMP_REG >> 8);
	  buf[1] = (uint8_t)READ_TEMP_REG;
	  HAL_I2C_Master_Transmit(&hi2c1, SHT_ADDR, buf, 2, 100);
	  HAL_I2C_Master_Receive(&hi2c1, SHT_ADDR, buf, 6, 100);

	  temp = temperature(buf);
	  hum = humidity(buf);
	*/
	  //printf("Humidity is %.2f %\r\n", hum);
	  //printf("Temperature is %.2f C\r\n", temp);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */

  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0;
  sTime.Minutes = 0;
  sTime.Seconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 1;
  sDate.Year = 0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 83;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 249999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 8399;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) //If the source is TIM2
	{
		  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	}
	if (htim->Instance == TIM3) //If the source is TIM2
	{
		//HAL_UART_Receive(&huart1, buf_GPS, 255, 1000);
		//HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
