/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
//#include "USART_INTERFACE.h"
#include "TIMERx_Interface.h"
#include "NVIC_INTERFACE.h"
#include "USART2_INTERFACE.h"

int main(void)
{

	u8 LOC_u8NewData = 0 ;
	u8 LOC_u8OldData = 0;

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock ( APB2_BUS , GPIOA_RCC                   ) ;
	MRCC_VidEnablePeripheralClock ( APB1_BUS , USART2_RCC                  ) ;

	MGPIO_VidSetPinDirection      ( GPIOA , PIN9  , OUTPUT_SPEED_2MHZ_AFPP ) ;
	MGPIO_VidSetPinDirection      ( GPIOA , PIN10 , INPUT_FLOATING         ) ;

	MGPIO_VidSetPortDirection     ( GPIOA , LOW  , OUTPUT_SPEED_2MHZ_PP    ) ;

	MUSART2_VidInit();

	while(1){

		LOC_u8NewData = MUSART2_u8RecCharSynch();

		if( LOC_u8NewData > '0' && LOC_u8NewData < '9' ){

			LOC_u8NewData -= 48 ;
			LOC_u8OldData |= 1 << ( LOC_u8NewData - 1 ) ;
			MGPIO_VidSetPortValue( GPIOA , PIN0 , LOW );

		}
		if( LOC_u8NewData == 'c' ){

			MGPIO_VidSetPortValue( GPIOA , PIN0 , LOW );
			LOC_u8OldData = 0;

		}
		if( LOC_u8NewData == 'c' ){

			MGPIO_VidSetPortValue( GPIOA , PIN0 , LOW );
			LOC_u8OldData = 0;

		}

	}

	return 0;
}

