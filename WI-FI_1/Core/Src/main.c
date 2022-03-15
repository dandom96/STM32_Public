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
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
uint8_t buf_WIFI[5000] = {0};
static uint8_t AT_RESET[] = "AT+RST\r\n"; //Reset 11bytes
static uint8_t AT[] = "AT\r\n"; //Check status 11bytes
static uint8_t ATpGMR[] = "AT+GMR\r\n"; //Check status 133 bytes
static uint8_t ATpUART_CUR[]= "AT+UART_DEF?\r\n";  //check UART params
static uint8_t AT_RESTORE[]= "AT+RESTORE\r\n";  //Restore Factory settings 11bytes
static uint8_t CWMODE[] = "AT+CWMODE_CUR=?\r\n";      //Current WiFi Mode
static uint8_t CWMODE1[] = "AT+CWMODE=1\r\n";      //Station WiFi Mode
static uint8_t CWLAP[] = "AT+CWLAP\r\n";      //WIFI available connections
static uint8_t CWJAP[] = "AT+CWJAP_DEF=\"DANIIlGROUP\",\"ddgroup72\"\r\n";      //WIFI available connections
static uint8_t CWJAP_ST[] = "AT+CWJAP=?\r\n";      //WIFI connection status
static uint8_t CIFSR[] = "AT+CIFSR\r\n";      //Get IP address
static uint8_t CIPMUX[] = "AT+CIPMUX=1\r\n";      //Enable miltiple connections
static uint8_t CIPSERVER[] = "AT+CIPSERVER=1,80\r\n";      //Create Server
static uint8_t CIPSEND[] = "AT+CIPSEND=0,18\r\n";      //Open channel, and ENTER data length
static uint8_t Message1[] = "Lizka Kiska Love\r\n";      //Send data
static uint8_t CIPCLOSE[] = "AT+CIPCLOSE=0\r\n";      //CLose Channel
uint8_t length;
uint8_t length1;
//AVA SYSTEMS forever
HAL_StatusTypeDef ret;
/* USER CODE END PV */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
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
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  length = sizeof(Message1);
  length1 = strlen(Message1);
  //GET AT OK
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, AT, sizeof(AT), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 11, 100);

  ret = HAL_UART_Transmit(&huart2, AT, sizeof(AT), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 11, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //GET Current Wifi MODE
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CWMODE, sizeof(CWMODE), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 200, 100);       //41

  ret = HAL_UART_Transmit(&huart2, CWMODE, sizeof(CWMODE), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 200, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //To station mode
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CWMODE1, sizeof(CWMODE1), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 200, 100);      //22

  ret = HAL_UART_Transmit(&huart2, CWMODE1, sizeof(CWMODE1), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 200, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //Version
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, ATpGMR, sizeof(ATpGMR), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 200, 100);     //138

  ret = HAL_UART_Transmit(&huart2, ATpGMR, sizeof(ATpGMR), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 200, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }
  //73 'I'73 'I'108 'l'
  //Available COnnections
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CWLAP, sizeof(CWLAP), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 5000, 10000);     //138

  ret = HAL_UART_Transmit(&huart2, CWLAP, sizeof(CWLAP), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 5000, 10000);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //WIFI connection
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CWJAP, sizeof(CWJAP), 10000);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 10000);     //138

  ret = HAL_UART_Transmit(&huart2, CWJAP, sizeof(CWJAP), 1000);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 1000);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //Get IP address
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CIFSR, sizeof(CIFSR), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 300, 100);     //138

  ret = HAL_UART_Transmit(&huart2, CIFSR, sizeof(CIFSR), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 300, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //Enable Multiple Connections
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CIPMUX, sizeof(CIPMUX), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 100);     //138

  ret = HAL_UART_Transmit(&huart2, CIPMUX, sizeof(CIPMUX), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //CReate Server
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CIPSERVER, sizeof(CIPSERVER), 100);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 100);     //138

  ret = HAL_UART_Transmit(&huart2, CIPSERVER, sizeof(CIPSERVER), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }
  HAL_Delay(1000);

  //Open Channel and transmit data length
  /*
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CIPSEND, sizeof(CIPSEND), 1000);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

  ret = HAL_UART_Transmit(&huart2, CIPSEND, sizeof(CIPSEND), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //Transmit Message
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, Message1, sizeof(Message1), 1000);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

  ret = HAL_UART_Transmit(&huart2, Message1, sizeof(Message1), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }

  //CLose channel
  printf("\r\nTransmit Message\r\n");
  ret = HAL_UART_Transmit(&huart1, CIPCLOSE, sizeof(CIPCLOSE), 1000);
  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

  ret = HAL_UART_Transmit(&huart2, CIPCLOSE, sizeof(CIPCLOSE), 100);
  printf("\r\nReceived Message\r\n");
  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
  for (int i=0; i<sizeof(buf_WIFI); i++)
  {
	  buf_WIFI[i] = 0;
  }
*/
  //Begin communication
  //printf("\r\nTransmit Message\r\n");
  //ret = HAL_UART_Transmit(&huart1, AT, sizeof(AT), 100);
  //ret = HAL_UART_Transmit(&huart2, AT, sizeof(AT), 100);
  //printf("\r\nReceived Message\r\n");
  //ret = HAL_UART_Receive(&huart1, buf_WIFI, 8, 100);
  //ret = HAL_UART_Transmit(&huart2, buf_WIFI, 8, 100);

  //Check version Info
  //printf("\r\nNew Message\r\n");
  //ret = HAL_UART_Transmit(&huart1, ATpGMR, sizeof(ATpGMR), 100);
  //ret = HAL_UART_Transmit(&huart2, ATpGMR, sizeof(ATpGMR), 100);

  //ret = HAL_UART_Receive(&huart1, buf_WIFI, 133, 100);
  //ret = HAL_UART_Transmit(&huart2, buf_WIFI, 133, 100);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //sizeof(test_cmd)
  while (1)
  {
	  printf("\r\nTransmit Message\r\n");
	  ret = HAL_UART_Transmit(&huart1, CIPSEND, sizeof(CIPSEND), 1000);
	  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

	  ret = HAL_UART_Transmit(&huart2, CIPSEND, sizeof(CIPSEND), 100);
	  printf("\r\nReceived Message\r\n");
	  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
	  for (int i=0; i<sizeof(buf_WIFI); i++)
	  {
		  buf_WIFI[i] = 0;
	  }

	  //Transmit Message
	  printf("\r\nTransmit Message\r\n");
	  ret = HAL_UART_Transmit(&huart1, Message1, sizeof(Message1), 1000);
	  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

	  ret = HAL_UART_Transmit(&huart2, Message1, sizeof(Message1), 100);
	  printf("\r\nReceived Message\r\n");
	  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
	  for (int i=0; i<sizeof(buf_WIFI); i++)
	  {
		  buf_WIFI[i] = 0;
	  }

	  //CLose channel
	  printf("\r\nTransmit Message\r\n");
	  ret = HAL_UART_Transmit(&huart1, CIPCLOSE, sizeof(CIPCLOSE), 1000);
	  ret = HAL_UART_Receive(&huart1, buf_WIFI, 100, 1000);     //138

	  ret = HAL_UART_Transmit(&huart2, CIPCLOSE, sizeof(CIPCLOSE), 100);
	  printf("\r\nReceived Message\r\n");
	  ret = HAL_UART_Transmit(&huart2, buf_WIFI, 100, 100);
	  for (int i=0; i<sizeof(buf_WIFI); i++)
	  {
		  buf_WIFI[i] = 0;
	  }
	  //Get AT OK
	  //printf("\r\nTransmit Message\r\n");
	  //ret = HAL_UART_Transmit(&huart1, AT, sizeof(AT), 100);
	  //ret = HAL_UART_Receive(&huart1, buf_WIFI, 11, 100);

	 // ret = HAL_UART_Transmit(&huart2, AT, sizeof(AT), 100);
	  //printf("\r\nReceived Message\r\n");
	 // ret = HAL_UART_Transmit(&huart2, buf_WIFI, 11, 100);


	  //Check version Info
	  //printf("\r\nNew Message\r\n");
	  //ret = HAL_UART_Transmit(&huart1, ATpGMR, sizeof(ATpGMR), 100);
	  //ret = HAL_UART_Transmit(&huart2, ATpGMR, sizeof(ATpGMR), 100);

	  //ret = HAL_UART_Receive(&huart1, buf_WIFI, 133, 100);
	  //ret = HAL_UART_Transmit(&huart2, buf_WIFI, 133, 100);
	  //HAL_Delay(1000);

	  //Get UART params
	  //printf("\r\nNew Message\r\n");
	  //ret = HAL_UART_Transmit(&huart1, ATpUART_CUR, sizeof(ATpUART_CUR), 100);
	  //ret = HAL_UART_Transmit(&huart2, ATpUART_CUR, sizeof(ATpUART_CUR), 100);

	  //ret = HAL_UART_Receive(&huart1, buf_WIFI, 200, 100);
	  //ret = HAL_UART_Transmit(&huart2, buf_WIFI, 200, 100);
	  //HAL_Delay(1000);

	  //for (int i=0; i<sizeof(buf_WIFI); i++)
	  //{
		 // buf_WIFI[i] = 0;
	  //}
	  //HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
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
  htim2.Init.Prescaler = 84;
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
  huart1.Init.BaudRate = 115200;
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
