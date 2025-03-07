/*
 * _7segment_interface.h
 *
 * Created: 2/14/2025 3:19:10 PM
 *  Author: Ahmad abdullatif
 */


#ifndef SEGMENT_INTERFACE_H_
#define SEGMENT_INTERFACE_H_

#define SSD_FIRST_SSD  0
#define SSD_SECOND_SSD 1

void SSD_voidInit();
void SSD_voidDisplayOneDigitNumber(u8 copy_u8SsdId,u8 copy_u8Digit);
void SSD_voidDisplayTwoDigitNumber(u16 copy_u16Number);





#endif /* 7SEGMENT_INTERFACE_H_ */
