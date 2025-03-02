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

void TIMER1_voidInit(u8 copy_u8ModeOfOperation){
	switch(copy_u8ModeOfOperation){
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A_REGISTER,WGM10_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM11_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM12_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM13_BIT);
		//setting preload value
		TCNT1_REGISTER = TIMER1_PRELOAD_VALUE;
		//enabling overflow interrupt
		SET_BIT(TIMSK_REGISTER,TOIE1_BIT);
		break;
		
		
		case TIMER1_CTC_MODE:
		CLEAR_BIT(TCCR1A_REGISTER,WGM10_BIT);
		CLEAR_BIT(TCCR1A_REGISTER,WGM11_BIT);
		SET_BIT  (TCCR1B_REGISTER,WGM12_BIT);
		CLEAR_BIT(TCCR1B_REGISTER,WGM13_BIT);
		//setting OCR value
		OCR1A_REGISTER = TIMER1_OCRA_VALUE;
		//enabling OCRA interrupt
		SET_BIT(TIMSK_REGISTER,OCIE1A_BIT);
		break;
	}
	
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


void __vector_7 (void)__attribute__((signal));
void __vector_7 (void){
	static u16 local_u16ONumberOfInterruptsCounter = 0;
	++local_u16ONumberOfInterruptsCounter;
	if(local_u16ONumberOfInterruptsCounter == TIMER1_NUMBER_OF_INTERRUPTS){
		local_u16ONumberOfInterruptsCounter = 0;
		priv_pfCallBackFunction();
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void){
	static u16 local_u16ONumberOfInterruptsCounter = 0;
	++local_u16ONumberOfInterruptsCounter;
	if(local_u16ONumberOfInterruptsCounter == TIMER1_NUMBER_OF_INTERRUPTS){
		local_u16ONumberOfInterruptsCounter = 0;
		TCNT1_REGISTER = TIMER1_PRELOAD_VALUE;
		priv_pfCallBackFunction();
	}
}