/*
 * TIMER2_interface.h
 *
 * Created: 2/18/2025 12:31:11 PM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

//modes of operation options
#define TIMER2_NORMAL_MODE   0
#define TIMER2_CTC_MODE      1



//timer0 APIs
void TIMER2_voidInit               (u8 copy_u8ModeOfOperatino);
void TIMER2_voidStartTimer         (void);
void TIMER2_voidStopTimer          (void);
void TIMER2_voidSetCallBackFunction(void(*pf)(void));




#endif /* TIMER2_INTERFACE_H_ */
