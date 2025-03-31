/*
 * RTOS_interface.h
 *
 * Created: 3/14/2025 8:31:07 AM
 *  Author: Ahmad abdullatif
 */


#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

#define TASK_ACTIVE    1
#define TASK_SUSPENDED 0

typedef struct{
	u8 status;
	u16 taskPeriodicity;
	void (*pfTask)(void);
}task;


void RTOS_voidStartScheduling();
void RTOS_voidCreateTask     (u8 copy_u8priority,u16 copy_u16Periodicity,void (*copy_pfCode)(void));
void RTOS_voidDeleteTask     (u8 copy_u8Priority);
void RTOS_voidSuspendTask    (u8 copy_u8priority);
void RTOS_voidResumeTask     (u8 copy_u8priority);


#endif /* RTOS_INTERFACE_H_ */
