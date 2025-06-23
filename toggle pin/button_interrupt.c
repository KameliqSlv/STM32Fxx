#include <string.h>
#include "ssrm32f407xx.h"

/*
 * Connect an external button to PD5 pin and toggle the led whenever interrupt is triggered by the button press
 * Interrupt should be triggered during falling edge of putton press
 */


void delay(void){
	// this will introduce ~200ms delay
	for(uint32_t i = 0; i < 500000 / 2; i++);
}

// button 	PD5

int main(void){
	GPIO_Handle_t button_ext;
	GPIO_Handle_t led;

	// reset the memory
	memset(&button_ext, 0, sizeof(button_ext));
	memset(&led, 0, sizeof(led));

	// button
	button_ext.pGPIOx = GPIOD;
	button_ext.pGPIO_PinConfig.GPIO_PinNum = GPIO_PIN_NO_5;
	button_ext.pGPIO_PinConfig.GPIO_Mode = GPIO_MODE_IT_FT;
	button_ext.pGPIO_PinConfig.GPIO_Speed = GPIO_SPEED_VHIGH;
	button_ext.pGPIO_PinConfig.GPIO_Pu_Pd = GPIO_PU;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&button_ext);


	// LED
	led.pGPIOx = GPIOD;
	led.pGPIO_PinConfig.GPIO_PinNum = GPIO_PIN_NO_12;
	led.pGPIO_PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT;
	led.pGPIO_PinConfig.GPIO_Speed = GPIO_SPEED_VHIGH;
	led.pGPIO_PinConfig.GPIO_OutputType = GPIO_OUT_TYPE_PP;
	led.pGPIO_PinConfig.GPIO_Pu_Pd = GPIO_NO_PUPD;

	GPIO_Init(&led);

	// IRQ configuration
	GPIO_PriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);


	while(1);
	return 0;

}


void EXTI9_5_IRQHandler(void){
	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_5);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
}
