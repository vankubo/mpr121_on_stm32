#include "mpr121_config.h"

/*********************
 ****I2C Functions****
 *********************/ 

void i2cInit(void)
{ 
	IIC_Init();
}


void i2cSendStart(void)
{  
	IIC_Start();

}

void i2cSendStop(void)
{    
	// transmit stop condition
       IIC_Stop();
}

void i2cWaitForComplete(void)
{
	IIC_Wait_Ack();
} 

void i2cSendByte(unsigned char data)
{ 
	IIC_Send_Byte(data);
}

unsigned char i2cReceiveByte(unsigned char ackFlag)
{
	return IIC_Read_Byte(ackFlag);
}

/*******************
 * 外部中断配置
 *******************/
void mpr121_irqInit(void)
{
	
	 EXTI_Key_Config();
}


