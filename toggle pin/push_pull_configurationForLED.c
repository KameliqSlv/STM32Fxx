#include "ssrm32f407xx.h"

/*
 * 	Write a program to toggle the on board LED with some delay
 * 	use push pull configuration for the output pin
 */
void delay(void){
	for(uint32_t i = 0; i<5000; i++);
}

int main(void){
	GPIO_Handle_t GpioLedPin;

	GpioLedPin.pGPIOx = GPIOD;
	GpioLedPin.pGPIO_PinConfig->GPIO_PinNum = GPIO_PIN_NO_12;
	GpioLedPin.pGPIO_PinConfig->GPIO_Mode = GPIO_MODE_OUTPUT;
	GpioLedPin.pGPIO_PinConfig->GPIO_Speed = GPIO_SPEED_VHIGH;
	GpioLedPin.pGPIO_PinConfig->GPIO_OutputType = GPIO_OUT_TYPE_PP;
	GpioLedPin.pGPIO_PinConfig->GPIO_Pu_Pd = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLedPin);

	while(1){
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}
	return 0;
}
