 #ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//���Ŷ���
#define KEY1_INT_GPIO_PORT         GPIOA
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_0//EXTI���жϿ�
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA//EXTI�ź�Դ
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource0//EXTI�ź�Դ
#define KEY1_INT_EXTI_LINE         EXTI_Line0//EXTI�ж���
#define KEY1_INT_EXTI_IRQ          EXTI0_IRQn//NVIC�ж�Դ

#define KEY1_IRQHandler            EXTI0_IRQHandler

extern char key_pressed;
void EXTI_Key_Config(void);


#endif /* __EXTI_H */
