//mpr121配置文件，mpr121对硬件底层实现的接口
//包括iic通信和外部中断的实现
//日期 2019.7.11

#ifndef __MPR121_CONFIG_H
#define __MPR121_CONFIG_H
#include "types.h"
#include "myiic.h"//iic实现
#include "bsp_exti.h"//外部中断实现


#define TRUE 1
#define FALSE 0

// functions A 下列函数实现对iic通信函数的封装

//! Initialize I2C  interface
void i2cInit(void);


// Low-level I2C transaction commands 
//! Send an I2C start condition in Master mode
void i2cSendStart(void);

//! Send an I2C stop condition in Master mode
void i2cSendStop(void);

//! Wait for current I2C operation to complete
void i2cWaitForComplete(void);

//! Send an (address|R/W) combination or a data byte over I2C
void i2cSendByte(unsigned char data);

//! Receive a data byte over I2C  
// ackFlag = TRUE if recevied data should be ACK'ed
// ackFlag = FALSE if recevied data should be NACK'ed
unsigned char i2cReceiveByte(unsigned char ackFlag);

//functions B 下列函数实现对外部中断的封装
void mpr121_irqInit(void);
#endif


