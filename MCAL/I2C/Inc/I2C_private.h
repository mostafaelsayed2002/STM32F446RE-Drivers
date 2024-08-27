#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

// I2C Register Definition

// I2C_CR1
#define PE 0
#define SMBUS 1
#define SMBTYPE 3
#define ENARP 4
#define ENPEC 5
#define ENGC 6
#define NOSTRETCH 7
#define START 8
#define STOP 9
#define ACK 10
#define POS 11
#define PEC 12
#define ALERT 13
#define SWRST 15

// I2C_CR2
#define FREQ 0
#define ITERREN 8
#define ITEVTEN 9
#define ITBUFEN 10
#define DMAEN 11
#define LAST 12

// I2C_OAR1
#define ADD0 0
#define ADD 1
#define ADD8 8
#define ADDMODE 15

// I2C_OAR2
#define ENDUAL 0
#define ADD2 1

// I2C_SR1
#define SB 0
#define ADDR 1
#define BTF 2
#define ADD10 3
#define STOPF 4
#define RXNE 6
#define TXE 7
#define BERR 8
#define ARLO 9
#define AF 10
#define OVR 11
#define PECERR 12
#define TIMEOUT 14
#define SMBALERT 15

// I2C_CCR
#define DUTY 14
#define F_S 15

#endif
