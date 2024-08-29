#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

// UART Registers

// SR
#define UART_SR_PE 0
#define UART_SR_FE 1
#define UART_SR_NF 2
#define UART_SR_ORE 3
#define UART_SR_IDLE 4
#define UART_SR_RXNE 5
#define UART_SR_TC 6
#define UART_SR_TXE 7
#define UART_SR_LBD 8
#define UART_SR_CTS 9

// CR1
#define UART_CR1_SBK 0
#define UART_CR1_RWU 1
#define UART_CR1_RE 2
#define UART_CR1_TE 3
#define UART_CR1_IDLEIE 4
#define UART_CR1_RXNEIE 5
#define UART_CR1_TCIE 6
#define UART_CR1_TXEIE 7
#define UART_CR1_PEIE 8
#define UART_CR1_PS 9
#define UART_CR1_PCE 10
#define UART_CR1_WAKE 11
#define UART_CR1_M 12
#define UART_CR1_UE 13
#define UART_CR1_OVER8 15

// CR2
#define UART_CR2_ADD 0
#define UART_CR2_LBDL 5
#define UART_CR2_LBDIE 6
#define UART_CR2_LBCL 8
#define UART_CR2_CPHA 9
#define UART_CR2_CPOL 10
#define UART_CR2_CLKEN 11
#define UART_CR2_STOP 12
#define UART_CR2_LINEN 14

#endif