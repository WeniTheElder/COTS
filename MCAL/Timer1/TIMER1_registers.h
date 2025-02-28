/*
 * TIMER1_registers.h
 *
 * Created: 2/18/2025 11:44:39 AM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER1_REGISTERS_H_
#define TIMER1_REGISTERS_H_

#define TCCR1A_REGISTER (*(volatile u8*)0x4F)   //Timer/Counter1 control register A
#define COM1A1_BIT 7
#define COM1A0_BIT 6
#define COM1B1_BIT 5
#define COM1B0_BIT 4
#define FOC1A_BIT  3
#define FOC1B_BIT  2
#define WGM11_BIT  1
#define WGM10_BIT  0

#define TCCR1B_REGISTER (*(volatile u8*)0x4E)   //Timer/Counter1 control register B
#define ICNC1_BIT  7
#define ICES1_BIT  6
#define WGM13_BIT  4
#define WGM12_BIT  3
#define CS12_BIT   2
#define CS11_BIT   1
#define CS10_BIT   0

#define TCNT1_REGISTER (*(volatile u16*)0x4C)  //timer/counter1 register
#define OCR1A_REGISTER (*(volatile u16*)0x4A)  //output compare match register A
#define OCR1B_REGISTER (*(volatile u16*)0x48)  //output compare match register B
#define ICR1_REGISTER  (*(volatile u16*)0x46)  //input capture register 

#define TIMSK_REGISTER (*(volatile u8*)0x59)   //Timer/Counter interrupt mask register
#define TICIE1_BIT 5 
#define OCIE1A_BIT 4
#define OCIE1B_BIT 3
#define TOIE1_BIT  2

#define TIFR_REGISTER (*(volatile u8*)0x58)    //Timer/Counter interrupt flag register
#define ICF1_BIT   5 
#define OCF1A_BIT  4
#define OCF1B_BIT  3
#define TOV1_BIT   2





#endif /* TIMER1_REGISTERS_H_ */
