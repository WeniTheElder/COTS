/*
 * spi_interface.h
 *
 * Created: 10/10/2024 5:36:22 PM
 *  Author: Ahmad abdullatif
 */


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "std_types.h"

#define SPI_MASTER_NODE 0
#define SPI_SLAVE_NODE  1

void SPI_voidInit  (u8 copy_u8NodeType);
void SPI_voidTxChar(u8 copy_u8Data);
void SPI_voidRxChar(u8* copy_pu8Data);

#endif /* SPI_INTERFACE_H_ */
