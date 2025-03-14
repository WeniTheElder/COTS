/*
 * TIMER2_program.c
 *
 * Created: 2/18/2025 12:31:33 PM
 *  Author: Ahmad abdullatif
 */
#include "std_types.h"
#include "bit_math.h"
#include "TIMER2_interface.h"
#include "TIMER2_registers.h"
#include "TIMER2_config.h"

static void(*priv_pfCallBackFucntion)(void);

void TIMER2_voidInit(u8 copy_u8ModeOfOperatino){
	switch(copy_u8ModeOfOperatino){
		case TIMER2_NORMAL_MODE:
		CLEAR_BIT(TCCR2_REGISTER,WGM20_BIT);
		CLEAR_BIT(TCCR2_REGISTER,WGM21_BIT);
		//setting preload value
		TCNT2_REGISTER = TIMER2_PRELOAD_VALUE;
		//enable overflow interrupt
		SET_BIT(TIMSK_REGISTER,TOIE2_BIT);
		break;
		case TIMER2_CTC_MODE:
		CLEAR_BIT(TCCR2_REGISTER,WGM20_BIT);
		SET_BIT  (TCCR2_REGISTER,WGM21_BIT);
		//setting OC value in OCR2
		OCR2_REGISTER = TIMER2_OCR2_VALUE;
		//enable output compare match interrupt
		SET_BIT(TIMSK_REGISTER,OCIE2_BIT);
		break;
	}
	
	
}
void TIMER2_voidStartTimer(void){
	//activating the timer/counter by selecting prescaler value to 64
	CLEAR_BIT(TCCR2_REGISTER,CS20_BIT);
	CLEAR_BIT(TCCR2_REGISTER,CS21_BIT);
	SET_BIT  (TCCR2_REGISTER,CS22_BIT);
}
void TIMER2_voidStopTimer(void){
	CLEAR_BIT(TCCR2_REGISTER,CS20_BIT);
	CLEAR_BIT(TCCR2_REGISTER,CS21_BIT);
	CLEAR_BIT(TCCR2_REGISTER,CS22_BIT);
}
void TIMER2_voidSetCallBackFunction(void(*pf)(void)){
	priv_pfCallBackFucntion = pf;
}


void __vector_5 (void) __attribute__ ((signal));
void __vector_5 (void){
	static u16 local_u16OverflowCounter = 0;
	++local_u16OverflowCounter;
	if(local_u16OverflowCounter == TIMER2_NUMBER_OF_OVERFLOWS){
		local_u16OverflowCounter = 0;
		TCNT2_REGISTER = TIMER2_PRELOAD_VALUE;
		priv_pfCallBackFucntion();
	}
}


void __vector_4 (void) __attribute__ ((signal));
void __vector_4 (void){
	static u16 local_u16overFlowsCounterr = 0;
	local_u16overFlowsCounterr++;
	if(local_u16overFlowsCounterr == TIMER2_NUMBER_OF_OVERFLOWS){
		local_u16overFlowsCounterr = 0;
		priv_pfCallBackFucntion();
	}
}