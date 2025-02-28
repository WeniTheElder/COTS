/*
 * TIMER1_interface.h
 *
 * Created: 2/18/2025 11:44:15 AM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

//modes of operation options
#define TIMER1_NORMAL_MODE   0
#define TIMER1_CTC_MODE      1
#define TIMER1_FAST_PWM_MODE 2


//timer1 APIs
void TIMER1_voidInit               (u8 copy_u8ModeOfOperatino);
void TIMER1_voidStartTimer         (void);
void TIMER1_voidStopTimer          (void);
void TIMER1_voidSetCallBackFunction(void(*pf)(void));



#endif /* TIMER1_INTERFACE_H_ */
