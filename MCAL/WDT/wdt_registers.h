/*
 * wdt_registers.h
 *
 * Created: 3/3/2025 9:36:18 PM
 *  Author: Ahmad abdullatif
 */


#ifndef WDT_REGISTERS_H_
#define WDT_REGISTERS_H_


#define WDTCR_REGISTER (*(volatile u8*)0x41)
#define WDTOE_BIT  4
#define WDE_BIT    3
#define WDP2_BIT   2
#define WDP1_BIT   1
#define WDP0_BIT   0




#endif /* WDT_REGISTERS_H_ */
