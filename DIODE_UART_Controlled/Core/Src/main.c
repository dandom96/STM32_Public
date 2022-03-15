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
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t b = 0;
uint8_t a[1] = "0";
uint8_t com_G =0;
uint8_t com_R =0;
uint8_t com_Y =0;
uint8_t com_W =0;
uint8_t TX_data_0[19] = "All Leds are OFF\n\r";
uint8_t TX_data_G_ON[19] = "Green Led is ON\n\r";
uint8_t TX_data_G_OF[20] = "Green Led is OFF\n\r";
uint8_t TX_data_R_ON[16] = "Red Led is ON\n\r";
uint8_t TX_data_R_OF[17] = "Red Led is OFF\n\r";
uint8_t TX_data_Y_ON[19] = "Yellow Led is ON\n\r";
uint8_t TX_data_Y_OF[20] = "Yellow Led is OFF\n\r";
uint8_t TX_data_W_ON[18] = "White Led is ON\n\r";
uint8_t TX_data_W_OF[19] = "White Led is OFF\n\r";

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	  HAL_UART_Receive_IT(&huart2, a, 1);

		  if(a[0]=='0')
		  {
			  b=0;
			  HAL_UART_Transmit(&huart2, TX_data_0, 19, 10);
			  com_W=0;
			  com_G=0;
			  com_R=0;
			  com_Y=0;
		  }

		  if(a[0]=='1')
		  {
			  b=1;
			  com_G++;
			  if(com_G % 2==1)
			  {
				  HAL_UART_Transmit(&huart2, TX_data_G_ON, 19, 10);
			  }
			  else
			  {
				  HAL_UART_Transmit(&huart2, TX_data_G_OF, 20, 10);
			  }
		  }

		  if(a[0]=='2')
		  {
			  b=2;
			  com_R++;
			  if(com_R % 2==1)
			  {
				  HAL_UART_Transmit(&huart2, TX_data_R_ON, 16, 10);
			  }
			  else
			  {
				  HAL_UART_Transmit(&huart2, TX_data_R_OF, 17, 10);
			  }
		  }

		  if(a[0]=='3')
		  {
			  b=3;
			  com_Y++;
			  if(com_Y % 2==1)
			  {
				  HAL_UART_Transmit(&huart2, TX_data_Y_ON, 19, 10);
			  }
			  else
			  {
				  HAL_UART_Transmit(&huart2, TX_data_Y_OF, 20, 10);
			  }
		  }
		  if(a[0]=='4')
		  {
			  b=4;
			  com_W++;
			  if(com_W % 2==1)

			  {
				  HAL_UART_Transmit(&huart2, TX_data_W_ON, 18, 10);
			  }
			  else
			  {
				  HAL_UART_Transmit(&huart2, TX_data_W_OF, 19, 10);
			  }
		  }
		  else
		  {
		    __NOP();
		  }
		  switch (b)
		  	  {
		  	  case 0:
		  		  //All LEDS are off
		  		  HAL_GPIO_WritePin(GPIOA, GREEN1_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(WHITE1_GPIO_Port, WHITE1_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOA, RED1_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOA, YELLOW1_Pin, GPIO_PIN_RESET);
		  		  break;
		  	  case 1:
		  		  //Green LED is ON
		  		  //HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);
		  		  HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
		  		  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		  		  break;
		  	  case 2:
		  		  //Red LED is ON
		  		  //HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);
		  		  //HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);
		  		  HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
		  		  break;
		  	  case 3:
		  		  //Yellow LED is ON
		  		  //HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_SET);
		  		  HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
		  		  break;
		  	  case 4:
		  		  //White LED is ON
		  		 //HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
		  		 //HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
		  		  //HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_SET);
		  		  HAL_GPIO_TogglePin(WHITE1_GPIO_Port, WHITE1_Pin);
		  		  break;
		  	  }

}
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//	  HAL_UART_Transmit_IT(&huart2, TX_data, 18);
//}
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
  /* USER CODE BEGIN 2 */
  //HAL_UART_Transmit_IT(&huart2, TX_data, 18);
  HAL_UART_Receive_IT(&huart2, a, 1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  //HAL_Delay(1000);
	 // HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	 /*
	  if(a[0]=='0')
	  {
		  b=0;
	  }
	  if(a[0]=='1')
	  {
		  b=1;
	  }
	  if(a[0]=='2')
	  {
		  b=2;
	  }
	  if(a[0]=='3')
	  {
		  b=3;
	  }
	  if(a[0]=='4')
	  {
		  b=4;
	  }
	  else
	  {
	    __NOP();
	  }
	  switch (b)
	  	  {
	  	  case 0:
	  		  //All LEDS are off
	  		  HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
	  		  break;
	  	  case 1:
	  		  //Green LED is ON
	  		  HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);
	  		  //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  		  break;
	  	  case 2:
	  		  //Red LED is ON
	  		  HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);
	  		  break;
	  	  case 3:
	  		  //Yellow LED is ON
	  		  HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_SET);
	  		  break;
	  	  case 4:
	  		  //White LED is ON
	  		  HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, GPIO_PIN_SET);
	  		  break;
	  	  }
	  	  */
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
  HAL_GPIO_WritePin(GPIOA, GREEN1_Pin|RED1_Pin|YELLOW1_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(WHITE1_GPIO_Port, WHITE1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : GREEN1_Pin RED1_Pin YELLOW1_Pin */
  GPIO_InitStruct.Pin = GREEN1_Pin|RED1_Pin|YELLOW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : WHITE1_Pin */
  GPIO_InitStruct.Pin = WHITE1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(WHITE1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

