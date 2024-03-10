/*
 * main.c
 *
 *  Created on: Feb 2, 2024
 *      Author: farida
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"

#include "../Include/MCAL/UART/UART_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/BUZZER/BUZZER_Interface.h"
#include "../Include/APP/APP/app.h"

#include <string.h>
#include <util/delay.h>

#define F_CPU 8000000UL

int main(){
	 MDIO_voidInit();
	 MUART_voidInit();
	 HLCD_voidInit();
	 while(1){
		 u8 login=0;
		login=home();
		 if(login==1){
			 control(); }
	 }
 }
