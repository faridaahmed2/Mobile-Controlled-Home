/*
 * RELAY_Interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: farida
 */

#ifndef INCLUDE_HAL_RELAY_RELAY_INTERFACE_H_
#define INCLUDE_HAL_RELAY_RELAY_INTERFACE_H_

void HRELAY_voidTurnOn  (DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID);
void HRELAY_voidTurnOff  (DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID);

#endif /* INCLUDE_HAL_RELAY_RELAY_INTERFACE_H_ */
