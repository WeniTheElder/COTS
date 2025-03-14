/*
 * hc_05_program.c
 *
 * Created: 3/12/2025 2:29:33 PM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "uart_interface.h"



void hc_05_voidInit(void){
	u8 local_u8DummyChar;
	for(u8 local_u8Counter = 0;local_u8Counter < 3;++local_u8Counter){
		UART_voidRxChar(&local_u8DummyChar);
	}
}