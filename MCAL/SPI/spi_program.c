/*
 * spi_program.c
 *
 * Created: 3/10/2025 7:57:00 AM
 *  Author: Ahmad Abdullatif
 */
#include "spi_interface.h"
#include "spi_registers.h"
#include "bit_math.h"
#include "std_types.h"

void SPI_voidInit  (u8 copy_u8NodeType){
	//disable SPI interrupt
	CLEAR_BIT(SPCR_REG,SPIE_BIT);
	
	//enable SPI
	SET_BIT  (SPCR_REG,SPE_BIT);
	
	//select LSB first as a data order
	SET_BIT  (SPCR_REG,DORD_BIT);
	
	//select node type
	if(copy_u8NodeType == SPI_MASTER_NODE){
		SET_BIT  (SPCR_REG,MSTR_BIT);
	}
	else{
		CLEAR_BIT(SPCR_REG,MSTR_BIT);
	}
	
	//select leading edge as rising (clock polarity)
	SET_BIT  (SPCR_REG,CPOL_BIT);
	
	//select sampling is in the first half (clock phase)
	SET_BIT  (SPCR_REG,CPHA_BIT);
	
	//set SCK to Fosc/128
	SET_BIT(SPCR_REG,SPR1_BIT);
	SET_BIT(SPCR_REG,SPR0_BIT);
}
void SPI_voidTxChar(u8 copy_u8Data){
	//write data into SPDR
	SPDR_REG = copy_u8Data;
}
void SPI_voidRxChar(u8* copy_pu8Data){
	//busy wait for SPI interrupt flag (transmission complete)
	while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
	//read data from SPDR
	*copy_pu8Data = SPDR_REG;
}