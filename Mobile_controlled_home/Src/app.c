/*
 * app.c
 *
 *  Created on: Feb 1, 2024
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

u8 local_u8ReceivedData[10];
u8 username[10][10]={"farida","aya","azza","menna","mohamed","ahmed","karim","omar","mariam","dalia"};
u8 password[10][10]={"000","111","333","444","232","888","222","1111","0000","4444"};

u8 home()
{
	   u32 correct_user=0,count=0;
       u32 correct_password=0;


		while((correct_user==0)&&(count<3)){
			MUART_voidSendStringSyncNonBlocking("Enter Username\r\n");
			HLCD_voidClearDisplay();
			HLCD_voidDisplayString("Enter Username:");

			MUART_voidReadStringSyncBlocking(local_u8ReceivedData);

			for(u8 i=0;i<10;i++)
		{
				if(strcmp(local_u8ReceivedData,username[i])==0)
				{
				 correct_user=1;

				 HLCD_voidClearDisplay();
				 HLCD_voidDisplayString("Enter password:");
				 MUART_voidSendStringSyncNonBlocking("Enter password \r\n");
				 for (u8 k=0;k<3;k++){
					 MUART_voidReadStringSyncBlocking(local_u8ReceivedData);
				 if(strcmp(local_u8ReceivedData,password[i])==0)
				 {
					 correct_password=1;
					 break;
				 }
				 else{
					 if (k<2){
						 HLCD_voidClearDisplay();
						 HLCD_voidDisplayString("Wrong password");
						 HLCD_voidGoToPos (LCD_ROW2, LCD_COL1);
						 HLCD_voidDisplayString("try again");
					 MUART_voidSendStringSyncNonBlocking("Wrong password try again \r\n");
					 }
					 if(k==2){
						 HLCD_voidClearDisplay();
						 HLCD_voidDisplayString("wait for 5 sec");
						 MUART_voidSendStringSyncNonBlocking("Wrong password\r\n");
						 HBUZZER_TurnOn(DIO_PORTA,PIN1);
						 MUART_voidSendStringSyncNonBlocking("wait for 5 seconds to enter again\r\n");
						 _delay_ms(5000);
						 HBUZZER_TurnOff(DIO_PORTA,PIN1);

					 }
				 }
				}}}
	count++;}
			if((correct_user==0)&&(count==3)==1){
				HBUZZER_TurnOn(DIO_PORTA,PIN1);
				 HLCD_voidClearDisplay();
				 HLCD_voidDisplayString("wait for 5 sec");
				MUART_voidSendStringSyncNonBlocking("wait for 5 seconds to enter again\r\n");
				_delay_ms(5000);
				HBUZZER_TurnOff(DIO_PORTA,PIN1);

			}






    return correct_password;

	}
void control(){

	u8 select=0;
   while(select==0){
	HLCD_voidClearDisplay();
	HLCD_voidDisplayString("L:LED    D:DOOR");
	HLCD_voidGoToPos (LCD_ROW2, LCD_COL1);
	HLCD_voidDisplayString("F:FAN    S:EXIT");
	MUART_voidSendStringSyncNonBlocking("To control LED      Enter(L)\r\n"
						                 "To control DOOR     Enter(D)\r\n"
						                 "To control FAN      Enter(F)\r\n"
						                 "To Exit             Enter(S)\r\n");
	u8 choose=MUART_u8ReadByteSyncBlocking ();

	 switch(choose){
				 case'L':
					LED(); break;
				 case'D':
					 DOOR(); break;
				 case'F':
					 FAN();  break;

	case 'S': select=1;
				break;
	default:
	 HLCD_voidClearDisplay();
	 HLCD_voidDisplayString("WRONG");
	 MUART_voidSendStringSyncNonBlocking("WRONG\r\n");
	_delay_ms(200);
				 break;
				 }

				}}

void LED(){
	u8 select_1=0;
	while(select_1==0){
	 HLCD_voidClearDisplay();
	 HLCD_voidDisplayString("O:ON     F:OFF");
	 HLCD_voidGoToPos (LCD_ROW2, LCD_COL1);
	 HLCD_voidDisplayString("S:EXIT");
	 MUART_voidSendStringSyncNonBlocking("To TURN LED ON      Enter(O)\r\n"
							             "To TURN LED OFF     Enter(F)\r\n"
			                             "To Exit             Enter(S)\r\n"
							             );
	         u8 choose_2= MUART_u8ReadByteSyncBlocking();
	         switch(choose_2)
	            {
	              case 'O':HLED_voidTurnOn(DIO_PORTA, PIN0);
                     break;
	              case'F':HLED_voidTurnOff(DIO_PORTA, PIN0);
                     break;
	              case 'S': select_1=1;
	             		break;

	              default:
	            	  HLCD_voidClearDisplay();
	            	  HLCD_voidDisplayString("WRONG");
	            	  MUART_voidSendStringSyncNonBlocking("WRONG\r\n");
	            	  _delay_ms(200);
	            	  break;

	            }}

}
void FAN(){
	u8 select_1=0;
	while(select_1==0){
	 HLCD_voidClearDisplay();
	 HLCD_voidDisplayString("ON O:1 T:2 H:3");
	 HLCD_voidGoToPos (LCD_ROW2, LCD_COL1);
	 HLCD_voidDisplayString("F:OFF   S:EXIT");

	 MUART_voidSendStringSyncNonBlocking("To TURN FAN OFF             Enter(F)\r\n"
										 "To TURN FAN ON DEGREE 1     Enter(O)\r\n"
			                             "To TURN FAN ON DEGREE 2     Enter(T)\r\n"
			                             "To TURN FAN ON DEGREE 3     Enter(H)\r\n"
			                             "To Exit                     Enter(S)\r\n"
										 );

	       u8 choose_4= MUART_u8ReadByteSyncBlocking();
			 switch(choose_4)
			 {
				 case 'F':
					 MTIMER0_voidSetOCR0Value(0);

					 break;
				 case'O': MTIMER0_voidInit ();
					     MTIMER0_voidSetOCR0Value(102);
					 break;
				 case'T':MTIMER0_voidInit ();
					     MTIMER0_voidSetOCR0Value(178);
					 break;
				 case'H':MTIMER0_voidInit ();
					     MTIMER0_voidSetOCR0Value(250);
					 break;
				 case 'S': select_1=1;
						break;
				 default:
					 HLCD_voidClearDisplay();
					 HLCD_voidDisplayString("WRONG");
					 MUART_voidSendStringSyncNonBlocking("WRONG\r\n");
					 _delay_ms(200);
					 break;

								 }}


}
void DOOR(){
	u8 select_1=0;
	while(select_1==0){
	 HLCD_voidClearDisplay();
	 HLCD_voidDisplayString("O:ON     F:OFF");
	 HLCD_voidGoToPos (LCD_ROW2, LCD_COL1);
	 HLCD_voidDisplayString("S:EXIT");
	 MUART_voidSendStringSyncNonBlocking("To TURN DOOR ON      Enter(O)\r\n"
										 "To TURN DOOR OFF     Enter(F)\r\n"
			                             "To Exit              Enter(S)\r\n"
										  );
           u8 choose_3= MUART_u8ReadByteSyncBlocking();
			 switch(choose_3)
		     {
				 case 'O':HRELAY_voidTurnOn(DIO_PORTA, PIN2);
					  break;
				 case'F':HRELAY_voidTurnOff(DIO_PORTA, PIN2);
					  break;
				 case 'S': select_1=1;
				  break;

				 default:
					 HLCD_voidClearDisplay();
					 HLCD_voidDisplayString("WRONG");
					 MUART_voidSendStringSyncNonBlocking("WRONG\r\n");
					 _delay_ms(200);
					   break;

			 }}

}
