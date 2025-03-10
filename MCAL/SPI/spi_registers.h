/*
 * spi_registers.h
 *
 * Created: 3/10/2025 7:57:00 AM
 *  Author: Ahmad Abdullatif
 */


#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_

#define SPCR_REG  (*(volatile u8*)0x2D)
#define SPIE_BIT  7
#define SPE_BIT	  6
#define DORD_BIT  5
#define MSTR_BIT  4
#define CPOL_BIT  3
#define CPHA_BIT  2
#define SPR1_BIT  1
#define SPR0_BIT  0

#define SPSR_REG  (*(volatile u8*)0x2E)
#define SPIF_BIT  7
#define WCOL_BIT  6
#define SPI2X_BIT 0

#define SPDR_REG  (*(volatile u8*)0x2F)








#endif /* SPI_REGISTERS_H_ */
