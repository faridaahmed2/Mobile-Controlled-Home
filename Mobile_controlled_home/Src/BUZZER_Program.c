/*
 * BUZZER_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: farida
 */
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

// Include BUZZER
#include "../Include/HAL/BUZZER/BUZZER_Interface.h"
#include "../Include/HAL/BUZZER/BUZZER_Private.h"
#include "../Include/HAL/BUZZER/BUZZER_Cfg.h"

#define F_CPU 8000000UL

void HBUZZER_TurnOn(DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID){
	MDIO_voidSetPinValue(A_DIOPort, A_PINID, DIO_SET);
}

void HBUZZER_TurnOff(DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID)
{
	MDIO_voidSetPinValue(A_DIOPort, A_PINID, DIO_RESET);
}

