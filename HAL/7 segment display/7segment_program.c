/*
 * _7segment_program.c
 *
 * Created: 2/14/2025 3:19:43 PM
 *  Author: Ahmad abdullatif
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "7segment_config.h"
#include "7segment_interface.h"
#include "7segment_private.h"

void PRIV_voidWriteDigit(u8 copy_u8Digit){
	DIO_voidSetPinValue(SSD_A_PORT,SSD_A_PIN,GET_BIT(copy_u8Digit,0));
	DIO_voidSetPinValue(SSD_B_PORT,SSD_B_PIN,GET_BIT(copy_u8Digit,1));
	DIO_voidSetPinValue(SSD_C_PORT,SSD_C_PIN,GET_BIT(copy_u8Digit,2));
	DIO_voidSetPinValue(SSD_D_PORT,SSD_D_PIN,GET_BIT(copy_u8Digit,3));
}

void SSD_voidInit(){
	DIO_voidSetPinDirection(SSD_A_PORT,SSD_A_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_B_PORT,SSD_B_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_C_PORT,SSD_C_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_D_PORT,SSD_D_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_DIP_PORT,SSD_DIP_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_EN1_PORT,SSD_EN1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(SSD_EN2_PORT,SSD_EN2_PIN,DIO_OUTPUT);
}
void SSD_voidDisplayOneDigitNumber(u8 copy_u8SsdId,u8 copy_u8Digit){
	PRIV_voidWriteDigit(copy_u8Digit);
	switch(copy_u8SsdId){
		case SSD_FIRST_SSD:
		DIO_voidSetPinValue(SSD_EN1_PORT,SSD_EN1_PIN,DIO_HIGH);
		break;
		case SSD_SECOND_SSD:
		DIO_voidSetPinValue(SSD_EN2_PORT,SSD_EN2_PIN,DIO_HIGH);
		break;
	}
}
void SSD_voidDisplayTwoDigitNumber(u16 copy_u16Number){
	u8 local_u8FirstDigit,local_u8SecondDigit;
	local_u8FirstDigit = copy_u16Number%10;
	copy_u16Number /= 10;
	local_u8SecondDigit = copy_u16Number;
	DIO_voidSetPinValue(SSD_EN1_PORT,SSD_EN1_PIN,DIO_LOW);
	DIO_voidSetPinValue(SSD_EN2_PORT,SSD_EN2_PIN,DIO_LOW);
	PRIV_voidWriteDigit(local_u8FirstDigit);
	DIO_voidSetPinValue(SSD_EN2_PORT,SSD_EN2_PIN,DIO_HIGH);
	_delay_ms(10);
	DIO_voidSetPinValue(SSD_EN2_PORT,SSD_EN2_PIN,DIO_LOW);
	PRIV_voidWriteDigit(local_u8SecondDigit);
	DIO_voidSetPinValue(SSD_EN1_PORT,SSD_EN1_PIN,DIO_HIGH);
	_delay_ms(10);
}
