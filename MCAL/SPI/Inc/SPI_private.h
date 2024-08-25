#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

// SPI1 Control Register 1 (SPI1_CR1)
#define CPHA 0
#define CPOL 1
#define MSTR 2
#define BR 3
#define SPE 6
#define LSBFIRST 7
#define SSI 8
#define SSM 9
#define RXONLY 10
#define DFF 11
#define CRCNEXT 12
#define CRCEN 13
#define BIDIOE 14
#define BIDIMODE 15

// SPI1 Control Register 2 (SPI1_CR2)
#define RXDMAEN 0
#define TXDMAEN 1
#define SSOE 2
#define FRF 4
#define ERRIE 5
#define RXNEIE 6
#define TXEIE 7

// SPI1 Status Register (SPI1_SR)
#define RXNE 0
#define TXE 1
#define CHSIDE 2
#define UDR 3
#define CRCERR 4
#define MODF 5
#define OVR 6
#define BSY 7
#define FRE 8

#endif
