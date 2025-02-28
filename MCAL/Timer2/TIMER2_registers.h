/*
 * TIMER2_registers.h
 *
 * Created: 2/18/2025 12:30:51 PM
 *  Author: Ahmad abdullatif
 */


#ifndef TIMER2_REGISTERS_H_
#define TIMER2_REGISTERS_H_


#define TCCR2_REGISTER (*(volatile u8*)0x45)   //Timer/Counter control register
#define FOC2_BIT  7
#define WGM20_BIT 6
#define COM21_BIT 5
#define COM20_BIT 4
#define WGM21_BIT 3
#define CS22_BIT  2
#define CS21_BIT  1
#define CS20_BIT  0

#define TCNT2_REGISTER (*(volatile u8*)0x44)   //Timer/Counter register
#define OCR2_REGISTER  (*(volatile u8*)0x43)   //Timer/Counter output compare match

#define ASSR_REGISTER  (*(volatile u8*)0x42)   //Asynchronous status register
#define AS2_BIT    3
#define TCN2UB_BIT 2
#define OCR2UB_BIT 1
#define TCR2UB_BIT 0

#define TIMSK_REGISTER (*(volatile u8*)0x59)   //Timer/Counter interrupt_mask register
#define OCIE2_BIT 7 
#define TOIE2_BIT 6

#define TIFR_REGISTER  (*(volatile u8*)0x58)   //Timer/Counter interrupt flag register
#define OCF2_BIT 7
#define TOV2_BIT 6

#endif /* TIMER2_REGISTERS_H_ */
