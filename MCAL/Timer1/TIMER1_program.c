/*
 * TIMER1_program.c
 *
 * Created: 2/18/2025 11:44:51 AM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_registers.h"

static void(*priv_pfCallBackFunction)(void);

void TIMER1_voidInit(u8 copy_u8ModeOfOperatino){
	switch(copy_u8ModeOfOperatino){
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A_REGISTER,WGM10_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM11_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM12_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM13_BIT);
		//setting preload value
		TCNT1_REGISTER = TIMER1_PRELOAD_VALUE;
		break;
		case TIMER1_CTC_MODE:
		break;
	}
	//enabling overflow interrupt
	SET_BIT(TIMSK_REGISTER,TOIE1_BIT);
}
void TIMER1_voidStartTimer(void){
	//activating the timer/counter by setting prescaler value (1024)
	SET_BIT  (TCCR1B_REGISTER,CS10_BIT);
	CLEAR_BIT(TCCR1B_REGISTER,CS11_BIT);
	SET_BIT  (TCCR1B_REGISTER,CS12_BIT);
	
}
void TIMER1_voidStopTimer(void){
	CLEAR_BIT(TCCR1B_REGISTER,CS10_BIT);
	CLEAR_BIT(TCCR1B_REGISTER,CS11_BIT);
	CLEAR_BIT(TCCR1B_REGISTER,CS12_BIT);
}
void TIMER1_voidSetCallBackFunction(void(*pf)(void)){
	priv_pfCallBackFunction = pf;
}


void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	static u16 local_u16OverFlowCounter = 0;
	++local_u16OverFlowCounter;
	if(local_u16OverFlowCounter == TIMER1_NUMBER_OF_OVERFLOWS){
		local_u16OverFlowCounter = 0;
		TCNT1_REGISTER = TIMER1_PRELOAD_VALUE;
		priv_pfCallBackFunction();
	}
}