#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "usmart.h"	 
#include "mpr121.h"	 

 
/************************************************
 ALIENTEK战舰STM32开发板实验23
 IIC 实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 				 	
 int main(void)
 {	 
	unsigned char touch_key='A';
	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为115200
	LCD_Init();			   	//初始化LCD 	
	 IIC_Init();
LED_Init();
	 mpr121QuickConfig();//mpr121初始化
	 
 	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(30,50,200,16,16,"WarShip STM32");	
	LCD_ShowString(30,70,200,16,16,"IIC TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2015/1/15");	
	//LCD_ShowString(30,130,200,16,16,"KEY1:Write  KEY0:Read");	//显示提示信息		
	 LCD_ShowString(30,130,200,16,16,&touch_key);	//显示提示信息	
	 while(1)
	 {
		 touch_key=getPhoneNumber();
		 LCD_ShowString(30,180,200,16,16,&touch_key);	//显示提示信息		
	 }
 	
}
