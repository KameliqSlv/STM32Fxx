#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include "ssrm32f407xx.h"

typedef struct{
//	uint8_t GPIO_PonNumber;
	uint8_t GPIO_PinNum;			/* possible value from @GPIO_PIN_NUM*/
	uint8_t GPIO_Mode;				/* possible value from @GPIO_PIN_MODES*/
	uint8_t GPIO_Speed;				/* possible value from @GPIO_SPEED_MODES*/
	uint8_t GPIO_OutputType;		/* possible value from @GPIO_OUT_MODES*/
	uint8_t GPIO_Pu_Pd;				/* possible value from @GPIO_PUPU_MODES*/
	uint8_t GPIO_AltFuncMode;
}GPIO_PinConfig_t;


/*
 * 	This is handle structure for a GPIO pin
 */
typedef struct{
	// pointer to hold the base address of the GPIO peripheral
	GPIO_RegDef_t *pGPIOx;	/* this holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t *pGPIO_PinConfig;
} GPIO_Handle_t;


/*
 * @GPIO_PIN_NUM
 * 	GPIO pin number
 */
#define GPIO_PIN_NO_0 	0
#define GPIO_PIN_NO_1 	1
#define GPIO_PIN_NO_2 	2
#define GPIO_PIN_NO_3 	3
#define GPIO_PIN_NO_4 	4
#define GPIO_PIN_NO_5 	5
#define GPIO_PIN_NO_6 	6
#define GPIO_PIN_NO_7 	7
#define GPIO_PIN_NO_8 	8
#define GPIO_PIN_NO_9 	9
#define GPIO_PIN_NO_10 	10
#define GPIO_PIN_NO_11 	11
#define GPIO_PIN_NO_12 	12
#define GPIO_PIN_NO_13 	13
#define GPIO_PIN_NO_14 	14
#define GPIO_PIN_NO_15 	15


/*
 * 	@GPIO_PIN_MODES
 *  GPIO pin possible modes
 */
#define GPIO_MODE_INPUT 	0
#define GPIO_MODE_OUTPUT 	1
#define GPIO_MODE_ALT_FUNC 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_FRT	6

/*
 *	@GPIO_OUT_MODES
 * 	GPIO pin possible output modes
 */
#define GPIO_OUT_TYPE_PP 	0
#define GPIO_OUT_TYPE_OD	1

/*
 * 	@GPIO_SPEED_MODES
 * 	GPIO pin possible speed modes
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MID		1
#define GPIO_SPEED_HIGH		2
#define GPIO_SPEED_VHIGH 	3

/*
 * @GPIO_PUPU_MODES
 * 	GPIO pin possible pull-up or pull-dows resistor
 */
#define GPIO_NO_PUPD		0
#define GPIO_PU				1
#define GPIO_PD				2
#define GPIO_RESERVED		3

/*
 * **********************	APIs supported by this driver ************************************
 * For more information about APIs check the function definitions
 */

/*
 * 	Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);

/*
 * 	Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * 	Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);					// 1 port had 16 pins => 16 bits
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,  uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum);

/*
 * 	IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI);
void GPIO_IRQHandling(uint8_t pinNum);



#endif /* INC_STM32F407XX_GPIO_H_ */
