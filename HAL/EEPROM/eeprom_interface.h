﻿/*
 * eeprom_interface.h
 *
 * Created: 3/11/2024 8:12:28 AM
 *  Author: Ahmad Abdullatif
 */


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


              /*************** APIS PROTOTYPES ***************/

void EEPROM_voidInit     (void);
void EEPROM_voidWriteByte(u16 copy_u16WordAdd, u8 copy_u8Data);
void EEPROM_voidReadByte (u16 copy_u16WordAdd, u8* copy_pu8Data);


#endif /* EEPROM_INTERFACE_H_ */