/*
 * RTOS_TIMER0_program.c
 *
 * Created: 3/14/2025 7:19:51 AM
 *  Author: Ahmad abdullatif
 */
#include "bit_math.h"
#include "std_types.h"
#include "RTOS_TIEMR0_interface.h"
#include "RTOS_TIMER0_REGISTERS.h"



static void(*priv_pfCallBackFunction)(void);

void RTOS_TIMER0_voidInit(){
	CLEAR_BIT(TCCR0_REGISTER,WGM00_BIT);
	SET_BIT  (TCCR0_REGISTER,WGM01_BIT);
	//enable output compare match interrupt
	SET_BIT(TIMSK_REGISTER,OCIE0_BIT);
}


void RTOS_TIMER0_voidSetOCvalue(u8 copy_u8OutcompareValue){
	OCR0_REGISTER = copy_u8OutcompareValue;
}


void RTOS_TIMER0_voidStartTimer(void){
	//activating the timer/counter by selecting prescaler value to 64
	SET_BIT  (TCCR0_REGISTER,CS00_BIT);
	SET_BIT  (TCCR0_REGISTER,CS01_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS02_BIT);
	
}


void RTOS_TIMER0_voidSetCallBackFunction(void(*pf)(void)){
	priv_pfCallBackFunction = pf;
}


void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void){
	priv_pfCallBackFunction();
}