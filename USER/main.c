#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "usmart.h"	 
#include "mpr121.h"	 

 
/************************************************
 ALIENTEKս��STM32������ʵ��23
 IIC ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 				 	
 int main(void)
 {	 
	unsigned char touch_key='A';
	delay_init();	    	 //��ʱ������ʼ��	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ115200
	LCD_Init();			   	//��ʼ��LCD 	
	 IIC_Init();
LED_Init();
	 mpr121QuickConfig();//mpr121��ʼ��
	 
 	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(30,50,200,16,16,"WarShip STM32");	
	LCD_ShowString(30,70,200,16,16,"IIC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2015/1/15");	
	//LCD_ShowString(30,130,200,16,16,"KEY1:Write  KEY0:Read");	//��ʾ��ʾ��Ϣ		
	 LCD_ShowString(30,130,200,16,16,&touch_key);	//��ʾ��ʾ��Ϣ	
	 while(1)
	 {
		 touch_key=getPhoneNumber();
		 LCD_ShowString(30,180,200,16,16,&touch_key);	//��ʾ��ʾ��Ϣ		
	 }
 	
}
