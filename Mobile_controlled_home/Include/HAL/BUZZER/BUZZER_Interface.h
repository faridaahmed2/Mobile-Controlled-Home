/*
 * BUZZER_Interface.h
 *
 *  Created on: Feb 1, 2024
 *      Author: farida
 */

#ifndef INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_
#define INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_

void HBUZZER_TurnOn(DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID);
void HBUZZER_TurnOff(DIO_PORT_e A_DIOPort,DIO_PIN_e A_PINID);

#endif /* INCLUDE_HAL_BUZZER_BUZZER_INTERFACE_H_ */
