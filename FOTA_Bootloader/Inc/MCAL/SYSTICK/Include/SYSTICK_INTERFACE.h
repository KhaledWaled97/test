/*
 * SYSTICK_INTERFACE.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Group 3 Team D
 */
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#define MSTK_INT_EN   1
#define MSTK_INT_DIS  0

void MSTK_VidInit( void );

void MSTK_VidStart( u32 Copy_PreloadValue );

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );

void MSTK_voidStopInterval(void);

void MSTK_VidINTStatus( u8 Copy_u8Status );

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );

u8 MSTK_u8ReadFlag( void );

void MSTK_VidSetCallBack( void (*ptr)(void) );

#endif /* SYSTICK_INTERFACE_H_ */
