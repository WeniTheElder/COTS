/*
 * RTOS_program.c
 *
 * Created: 3/14/2025 8:30:48 AM
 *  Author: Ahmad abdullatif
 */

/*library stack*/
#include "std_types.h"
#include "bit_math.h"
/*MCAL*/
#include "GI_interface.h"
/*RTOS*/
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_TIEMR0_interface.h"


static task arrayOfTasks[RTOS_NUMBER_OF_TASKS];


void RTOS_voidStartScheduling(){
	GI_voidEnableGeneralInterrupt();
	RTOS_TIMER0_voidInit();
	RTOS_TIMER0_voidSetOCvalue(249);  //F_CPU = 15MHZ, precaller = 64,RTOS_TIME = 1ms
	RTOS_TIMER0_voidSetCallBackFunction(priv_voidSchedular);
	RTOS_TIMER0_voidStartTimer();
}
void RTOS_voidCreateTask(u8 copy_u8priority,u16 copy_u16Periodicity,void (*copy_pfCode)(void)){
	arrayOfTasks[copy_u8priority].pfTask = copy_pfCode;
	arrayOfTasks[copy_u8priority].taskPeriodicity = copy_u16Periodicity;
	arrayOfTasks[copy_u8priority].status = TASK_ACTIVE;
}

void priv_voidSchedular(){
	static u16 local_u16TickCounter = 1;
	u8 local_u8Counter = 0;
	for(local_u8Counter = 0;local_u8Counter<RTOS_NUMBER_OF_TASKS;++local_u8Counter){
		if(arrayOfTasks[local_u8Counter].pfTask != NULL && arrayOfTasks[local_u8Counter].status == TASK_ACTIVE){
			if(local_u16TickCounter%(arrayOfTasks[local_u8Counter].taskPeriodicity) == 0){
			 	arrayOfTasks[local_u8Counter].pfTask();
			}
		}
	}
	local_u16TickCounter++;
}

void RTOS_voidDeleteTask(u8 copy_u8Priority){
	arrayOfTasks[copy_u8Priority].pfTask = NULL;
}
void RTOS_voidSuspendTask(u8 copy_u8priority){
	arrayOfTasks[copy_u8priority].status = TASK_SUSPENDED;
}
void RTOS_voidResumeTask(u8 copy_u8priority){
	arrayOfTasks[copy_u8priority].status = TASK_ACTIVE;
}