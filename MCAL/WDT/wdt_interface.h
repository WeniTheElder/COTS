/*
 * wdt_interface.h
 *
 * Created: 3/3/2025 9:34:00 PM
 *  Author: Ahmad abdullatif
 */


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define WDT_TIME_16_3_MS 0
#define WDT_TIME_32_5_MS 1
#define WDT_TIME_65_MS   2
#define WDT_TIME_0_13_S  3
#define WDT_TIME_0_26_S  4
#define WDT_TIME_0_52_S  5
#define WDT_TIME_1_S     6
#define WDT_TIME_2_1_S   7

void WDT_voidEnable (u8 copy_u8TimeOut);
void WDT_voidDisable();



#endif /* WDT_INTERFACE_H_ */
