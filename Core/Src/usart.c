/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "stdio.h"
#include "stdint.h"
#include "string.h"
/* USER CODE END 0 */

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USART2 init function */

void MX_USART2_UART_Init(void)
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
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/**
  * @brief      串口回调函数,被串口的中断函数所调用
  * @param[in]  串口
  * @return     none
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  // 判断是由哪个串口触发的中断
  if(huart->Instance == USART2)
  {
    read_buffer_uart2[current_buffer_length_uart2] = single_buffer_uart2;
    current_buffer_length_uart2++;
    // 接收到数据马上使用串口2发送出去
    // HAL_UART_Transmit(&huart1, &single_buffer, 1, 100);
    // 重新使能串口1接收中断(否则只能接收一次)
    HAL_UART_Receive_IT(&huart2, &single_buffer_uart2, 1);
  }
  if(huart->Instance == USART3)
  {
    read_buffer_uart3[current_buffer_length_uart3] = single_buffer_uart3;
    current_buffer_length_uart3++;
    // 接收到数据马上使用串口3发送出去
    // HAL_UART_Transmit(&huart1, &single_buffer, 1, 100);
    // 重新使能串口1接收中断(否则只能接收一次)
    HAL_UART_Receive_IT(&huart3, &single_buffer_uart3, 1);
  }
}

/**
  * @brief      空闲中断处理函数(自己写的),目的是为了数据多发或者发送较快时不会出错
  * @param[in]  串口
  * @return     none
  */
void UART_IDLECallBack(UART_HandleTypeDef *huart)
{
  /*uart1 idle processing function*/
  if(huart == &huart2)
  {
    current_buffer_length_uart2 = 0;
		timeout_count = 0;
    PROTOCOL_Handle(huart);
    __HAL_UART_CLEAR_IDLEFLAG(huart); // 清除空闲中断标志(否则会一直不断进入中断)
  }
  if(huart == &huart3)
  {
    current_buffer_length_uart2 = 0;
		timeout_count = 0;
    PROTOCOL_Handle(huart);
    __HAL_UART_CLEAR_IDLEFLAG(huart); // 清除空闲中断标志(否则会一直不断进入中断)
  }
}

/**
  * @brief      上下位机通讯协议
	* 
	* 
	* 
  * @return     none
  */
void PROTOCOL_Handle(UART_HandleTypeDef *huart)
{
	uint8_t low_value = 0x00;
	uint8_t high_value = 0x00;
	if(huart == &huart2)
  {
		// CRC校验
		CRC16_Modbus(read_buffer_uart2, 6, &low_value, &high_value);
		//if (read_buffer_uart2[6] != low_value || read_buffer_uart2[7] != high_value)
		//		return;
		switch (read_buffer_uart2[1])
		{
			case 0x01: // 控制灯改变亮灭状态
			{
				
			} break;
			case 0x02:
			{
				memcpy(&steer, read_buffer_uart2 + 2, sizeof(int32_t));
				if(steer > 500) {
					steer = 500;
				} else if(steer < -500) {
					steer = -500;
				}
			} break;
			case 0x03:
			{
				memcpy(&speed, read_buffer_uart2 + 2, sizeof(int32_t));
				if(speed > 500) {
					speed = 500;
				} else if(speed < -500) {
					speed = -500;
				}
			} break;
		}
	}
	if(huart == &huart3)
  {
		// CRC校验
		CRC16_Modbus(read_buffer_uart3, 6, &low_value, &high_value);
		//if (read_buffer_uart2[6] != low_value || read_buffer_uart2[7] != high_value)
		//		return;
		switch (read_buffer_uart3[1])
		{
			case 0x01: // 控制灯改变亮灭状态
			{
				
			} break;
			case 0x02:
			{
				memcpy(&steer, read_buffer_uart3 + 2, sizeof(int32_t));
			} break;
			case 0x03:
			{
				memcpy(&speed, read_buffer_uart3 + 2, sizeof(int32_t));
			} break;
		}
	}
}

/**
  * @brief      CRC循环冗余校验
  * @param[in]  待校验的数组
  * @param[in]  待校验的数组的大小
  * @param[out] CRC码低字节
  * @param[out] CRC码高字节
  * @return     none
  */
void CRC16_Modbus(uint8_t input[], int size, uint8_t* low_value, uint8_t* high_value)
{
  uint16_t crc = 0xffff;
  for (int n = 0; n < size; n++) {/*此处的6 -- 要校验的位数为6个*/
    crc = input[n] ^ crc;
    for (int i = 0; i < 8; i++) {  /*此处的8 -- 指每一个char类型又8bit，每bit都要处理*/
      if (crc & 0x01) {
        crc = crc >> 1;
        crc = crc ^ 0xa001;
      }
      else {
        crc = crc >> 1;
      }
    }
  }
  *low_value = crc & 0xFF;
  *high_value = (uint8_t)(crc >> 8);
}

// 重定向c库函数printf到串口DEBUG_USART，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
  /* 发送一个字节数据到串口DEBUG_USART */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 1000);
  return (ch);
}

// 重定向c库函数scanf到串口DEBUG_USART，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
  int ch;
  HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, 1000);	
  return (ch);
}
/* USER CODE END 1 */
