/*
 * TIMERS_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: farida
 */
/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* TIMERS Directives		     					*/
/****************************************************/
#include "../include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/TIMERS/TIMERS_Private.h"
#include "../include/MCAL/TIMERS/TIMERS_Cfg.h"


#define NULL 0
void (*TIMER0_OVF_CALLBACK)(void) = NULL;
void (*TIMER0_CTC_CALLBACK)(void) = NULL;

void MTIMER0_voidInit (void){
 #if TIMER0_MODE == NORMAL_MODE
	// Set Wave Generation to Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	// Enable OVF Interrupt, and Disable CTC Interrupt

	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);

	// Start Timer by setting its Clock
	TCCR0 &= TIMER0_CLK_MASK;
	TCCR0 |= TIMER0_CLK;
 #elif TIMER0_MODE == PHASE_CORRECT_MODE
	 // Set Wave Generation Mode
			 SET_BIT(TCCR0,6);
			 CLR_BIT(TCCR0,3);
			 //Disable OVF Interrupt, and Disable CTC Interrupt
			 CLR_BIT(TIMSK,0);
			 CLR_BIT(TIMSK,1);
			 // Set Compare match value
			 OCR0 = OCR0_VALUE;
			 // SET OC0 Configuraion
			 // Start Timer by setting its Clock and also set OC0 Pin Mode
			 TCCR0 &= TIMER0_CLK_OCR_MASK;
			 TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));

 #elif TIMER0_MODE == CTC_MODE
	// Set Wave Generation to CTC Mode
		CLR_BIT(TCCR0,6);
		SET_BIT(TCCR0,3);
		//Disable OVF Interrupt, and Enble CTC Interrupt

		CLR_BIT(TIMSK,0);
		SET_BIT(TIMSK,1);
		// Set Compare match value
		 OCR0 = OCR0_VALUE;

		// Start Timer by setting its Clock and also set OC0 Pin Mode
		 TCCR0 &= TIMER0_CLK_OCR_MASK;
		 TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));

 #elif TIMER0_MODE == FAST_PWM_MODE
		 // Set Wave Generation to Fast PWM Mode
		 SET_BIT(TCCR0,6);
		 SET_BIT(TCCR0,3);
		 //Disable OVF Interrupt, and Disable CTC Interrupt
		 CLR_BIT(TIMSK,0);
		 CLR_BIT(TIMSK,1);
		 // Set Compare match value
		 OCR0 = OCR0_VALUE;
		 // SET OC0 Configuraion
		 // Start Timer by setting its Clock and also set OC0 Pin Mode
		 TCCR0 &= TIMER0_CLK_OCR_MASK;
		 TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));
#endif
}
void MTIMER0_voidSetPreloadValue (u8 A_u8NoOfTicks){
	TCNT0=A_u8NoOfTicks;
}
void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= TIMER0_CLK_MASK;
}
void MTIMER0_voidSetOCR0Value (u8 A_u8OCR0Value)
{
	OCR0 = A_u8OCR0Value;
}
void MTIMER0_voidSetOVFCallback (void (*A_PtrToFunc)(void)){
	if (A_PtrToFunc != NULL)
		{
			TIMER0_OVF_CALLBACK = A_PtrToFunc;
		}
}
void MTIMER0_voidSetCTCCallback (void (*A_PtrToFunc)(void))
{
	if (A_PtrToFunc != NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}


void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CALLBACK != NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}
void __vector_11(void)__attribute__((signal));
void __vector_11(void){
	if (TIMER0_OVF_CALLBACK != NULL)
		{
			TIMER0_OVF_CALLBACK();
		}
}
