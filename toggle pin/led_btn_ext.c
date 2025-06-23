

#include "ssrm32f407xx.h"

#define LOW 0
#define BUTTON_PRESS LOW
/*
 * 	program to connect external button to the pin PB12 and external LED to PA14
 * 	toggle the LED whenever the external button is pressesd
 */

void delay(void){
	for(uint32_t i = 0; i < 500000; i++);
}

// button is connected to port B pin 12  	PB12
// led is connected to port A pin 8		 	PA8

int main(void){
	GPIO_Handle_t LedPin;
	GPIO_Handle_t ButtonPin;

	// Configure button
	ButtonPin.pGPIOx = GPIOB;
	ButtonPin.pGPIO_PinConfig.GPIO_PinNum = GPIO_PIN_NO_12;
	ButtonPin.pGPIO_PinConfig.GPIO_Mode = GPIO_MODE_INPUT;
	ButtonPin.pGPIO_PinConfig.GPIO_Speed = GPIO_SPEED_VHIGH;
	ButtonPin.pGPIO_PinConfig.GPIO_Pu_Pd = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&ButtonPin);

	// Configure LED
	LedPin.pGPIOx = GPIOA;
	LedPin.pGPIO_PinConfig.GPIO_PinNum = GPIO_PIN_NO_8;
	LedPin.pGPIO_PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT;
	LedPin.pGPIO_PinConfig.GPIO_Speed = GPIO_SPEED_VHIGH;
	LedPin.pGPIO_PinConfig.GPIO_OutputType = GPIO_OUT_TYPE_PP;
	LedPin.pGPIO_PinConfig.GPIO_Pu_Pd = GPIO_PU;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&LedPin);

	while(1){
		if(GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12) == BUTTON_PRESS){
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
			delay();
		}
	}



	return 0;
}
