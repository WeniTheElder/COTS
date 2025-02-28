/*
 * Timer0_program.c
 *
 * Created: 2/17/2025 1:35:03 PM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"
#include "Timer0_registers.h"
#include "DIO_interface.h"


static void(*priv_pfCallBackFunction)(void);

void TIMER0_voidInit(u8 copy_u8ModeOfOperatino){
	switch(copy_u8ModeOfOperatino){
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0_REGISTER,WGM00_BIT);
		CLEAR_BIT(TCCR0_REGISTER,WGM01_BIT);
		//setting preload value
		TCNT0_REGISTER = TIMER0_PRELOAD_VALUE;
		break;
		case TIMER0_CTC_MODE:
		break;
	}
	//enabling overflow interrupt
	SET_BIT(TIMSK_REGISTER,TOIE0_BIT);
}
void TIMER0_voidStartTimer(void){
	//activating the timer/counter by selecting prescaler value
	SET_BIT  (TCCR0_REGISTER,CS00_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS01_BIT);
	SET_BIT  (TCCR0_REGISTER,CS02_BIT);
	
}
void TIMER0_voidStopTimer(void){
	CLEAR_BIT(TCCR0_REGISTER,CS00_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS01_BIT);
	CLEAR_BIT(TCCR0_REGISTER,CS02_BIT);
}
void TIMER0_voidSetCallBackFunction (void(*pf)(void)){
	priv_pfCallBackFunction = pf;
}

void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void){
	static u16 local_u16OverflowCounter = 0;
	++local_u16OverflowCounter;
	if(local_u16OverflowCounter == TIMER0_NUMBER_OF_OVERFLOWS){
		local_u16OverflowCounter = 0;
		TCNT0_REGISTER = TIMER0_PRELOAD_VALUE;
		priv_pfCallBackFunction();
	}
}