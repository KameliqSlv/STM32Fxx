#include "ssrm32f407xx.h"

#define BUTTON_PRESS 1
/*
 * 	program to toggle the on board LED whenever the board button is pressed
 */

void delay(void){
	for(uint32_t i = 0; i < 500000; i++);
}

// button is connected to port A pin 0  	PA0
// led is connected to port B pin 12	 	PD12

int main(void){
	GPIO_Handle_t LedPin;
	GPIO_Handle_t ButtonPin;

	// Configure button
	ButtonPin.pGPIOx = GPIOA;
	ButtonPin.pGPIO_PinConfig->GPIO_PinNum = GPIO_PIN_NO_0;
	ButtonPin.pGPIO_PinConfig->GPIO_Mode = GPIO_MODE_INPUT;
	ButtonPin.pGPIO_PinConfig->GPIO_Speed = GPIO_SPEED_VHIGH;
	ButtonPin.pGPIO_PinConfig->GPIO_Pu_Pd = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&ButtonPin);

	// Configure LED
	LedPin.pGPIOx = GPIOD;
	LedPin.pGPIO_PinConfig->GPIO_PinNum = GPIO_PIN_NO_12;
	LedPin.pGPIO_PinConfig->GPIO_Mode = GPIO_MODE_OUTPUT;
	LedPin.pGPIO_PinConfig->GPIO_Speed = GPIO_SPEED_VHIGH;
	LedPin.pGPIO_PinConfig->GPIO_OutputType = GPIO_OUT_TYPE_PP;
	LedPin.pGPIO_PinConfig->GPIO_Pu_Pd = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&LedPin);

	while(1){
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BUTTON_PRESS){
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay();
		}
	}



	return 0;
}
