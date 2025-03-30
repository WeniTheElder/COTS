/*
 * RTOS_TIEMR0_interface.h
 *
 * Created: 3/14/2025 7:19:16 AM
 *  Author: Ahmad abdullatif
 */


#ifndef RTOS_TIEMR0_INTERFACE_H_
#define RTOS_TIEMR0_INTERFACE_H_



void RTOS_TIMER0_voidInit               ();
void RTOS_TIMER0_voidStartTimer         (void);
void RTOS_TIMER0_voidSetOCvalue         (u8 copy_u8OutcompareValue);
void RTOS_TIMER0_voidSetCallBackFunction(void(*pf)(void));




#endif /* RTOS_TIEMR0_INTERFACE_H_ */
