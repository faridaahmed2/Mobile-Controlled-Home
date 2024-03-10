/*
 * RELAY_Program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: farida
 */

// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

// Include RELAY
#include "../Include/HAL/RELAY/RELAY_Interface.h"
#include "../Include/HAL/RELAY/RELAY_Private.h"
#include "../Include/HAL/RELAY/RELAY_Cfg.h"


/*
 * Including
 * -----------------------------------
 * LIB --> STD_TYPES.h , BIT_MATH.h
 * MCAL
 * HAL
 */


void HRELAY_voidTurnOn  (DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID)
{
	MDIO_voidSetPinValue(A_DIOPort, A_PINID, DIO_SET);
}
void HRELAY_voidTurnOff (DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID)
{
	MDIO_voidSetPinValue(A_DIOPort, A_PINID, DIO_RESET);
}
