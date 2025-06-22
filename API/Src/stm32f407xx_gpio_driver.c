/*****************************************************************
 * @fn
 *
  * @brief
  * @param[in]
  * @param[in]
  * @param[in]
  *
  * @return
  *
  * @note
  */

#include "stm32f407xx_gpio.h"
#include <stdint.h>


/*
 * 	Peripheral clock setup
 */

/*****************************************************************
 * @fn					- GPIO_PeriClockControl
 *
  * @brief				- this function enable and disable peripheral clock for the given GPIO port
  * @param[in]			- base address of GPIO peripheral
  * @param[in]			- ENABLE or DISABLE macros
  * @param[in]
  *
  * @return				- none
  *
  * @note
  */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI){
	if(ENorDI == ENABLE){
		if(pGPIOx == GPIOA){
			PA_PCLK_EN();
		} else if(pGPIOx == GPIOB){
			PB_PCLK_EN();
		} else if(pGPIOx == GPIOC){
			PC_PCLK_EN();
		} else if(pGPIOx == GPIOD){
			PD_PCLK_EN();
		} else if(pGPIOx == GPIOE){
			PE_PCLK_EN();
		} else if(pGPIOx == GPIOF){
			PF_PCLK_EN();
		} else if(pGPIOx == GPIOG){
			PG_PCLK_EN();
		} else if(pGPIOx == GPIOH){
			PH_PCLK_EN();
		} else if(pGPIOx == GPIOI){
			PI_PCLK_EN();
		}
	} else {
		if(pGPIOx == GPIOA){
			PA_PCLK_DI();
		} else if(pGPIOx == GPIOB){
			PB_PCLK_DI();
		} else if(pGPIOx == GPIOC){
			PC_PCLK_DI();
		} else if(pGPIOx == GPIOD){
			PD_PCLK_DI();
		} else if(pGPIOx == GPIOE){
			PE_PCLK_DI();
		} else if(pGPIOx == GPIOF){
			PF_PCLK_DI();
		} else if(pGPIOx == GPIOG){
			PG_PCLK_DI();
		} else if(pGPIOx == GPIOH){
			PH_PCLK_DI();
		} else if(pGPIOx == GPIOI){
			PI_PCLK_DI();
		}
	}
}

/*
 * 	Init and DeInit
 */

/*****************************************************************
 * @fn					- GPIO_Init
 *
  * @brief				- Initializes the given GPIO pin
  * @param[in]			- pointer to handle structure
  * @param[in]
  * @param[in]
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	// 1. Configure the mode of gpio pin
	uint32_t temp = 0;	//temp register
	if(pGPIOHandle -> pGPIO_PinConfig -> GPIO_Mode <= GPIO_MODE_ANALOG){
		temp = pGPIOHandle->pGPIO_PinConfig->GPIO_Mode << (2 * pGPIOHandle->pGPIO_PinConfig->GPIO_PinNum);
		pGPIOHandle -> pGPIOx -> MODER &= ~(0x3 << pGPIOHandle -> pGPIO_PinConfig -> GPIO_PinNum);				// clearing
		pGPIOHandle -> pGPIOx -> MODER |= temp;																	// setting
	} else {
		// interrupt mode
	}

	temp = 0;
	// 2. Configure the speed
	temp = pGPIOHandle -> pGPIO_PinConfig->GPIO_Speed <<( 2* pGPIOHandle -> pGPIO_PinConfig->GPIO_PinNum);
	pGPIOHandle -> pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle -> pGPIO_PinConfig->GPIO_PinNum);
	pGPIOHandle -> pGPIOx->OSPEEDR |= temp;

	temp= 0;
	// 3. Configure the pupd settings
	temp = pGPIOHandle->pGPIO_PinConfig->GPIO_Pu_Pd << (2* pGPIOHandle->pGPIO_PinConfig->GPIO_Pu_Pd);
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->pGPIO_PinConfig->GPIO_Pu_Pd);
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	// 4. Configure the output type
	temp = pGPIOHandle->pGPIO_PinConfig->GPIO_OutputType << (pGPIOHandle->pGPIO_PinConfig->GPIO_PinNum);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x3 << pGPIOHandle->pGPIO_PinConfig->GPIO_PinNum);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	// 5. Configure the alternate functionality
	if(pGPIOHandle->pGPIO_PinConfig->GPIO_Mode == GPIO_MODE_ALT_FUNC){
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->pGPIO_PinConfig->GPIO_PinNum / 8;
		temp2 = pGPIOHandle->pGPIO_PinConfig->GPIO_PinNum % 8;
		pGPIOHandle->pGPIOx->ALTF[temp1] &= ~(0xf << (4 * temp2));
		pGPIOHandle->pGPIOx->ALTF[temp1] |= pGPIOHandle->pGPIO_PinConfig->GPIO_AltFuncMode << (4 * temp2);
	}
}

/*****************************************************************
 * @fn					- GPIO_DeInit
 *
  * @brief				- Reset the GPIO peripheral register
  * @param[in]			- GPIO port base address
  * @param[in]
  * @param[in]
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
		GPIOA_REG_RESET();
	} else if(pGPIOx == GPIOB){
		GPIOB_REG_RESET();
	} else if(pGPIOx == GPIOC){
		GPIOC_REG_RESET();
	} else if(pGPIOx == GPIOD){
		GPIOD_REG_RESET();
	} else if(pGPIOx == GPIOE){
		GPIOE_REG_RESET();
	} else if(pGPIOx == GPIOF){
		GPIOF_REG_RESET();
	} else if(pGPIOx == GPIOG){
		GPIOG_REG_RESET();
	} else if(pGPIOx == GPIOH){
		GPIOH_REG_RESET();
	} else if(pGPIOx == GPIOI){
		GPIOI_REG_RESET();
	}

}

/*
 * 	Data read and write
 */

/*****************************************************************
 * @fn					- GPIO_ReadFromInputPin
 *
  * @brief				- Reads the value of the given input pin
  * @param[in]			- GPIO port base address
  * @param[in]			- pin number to read (0 - 15)
  * @param[in]
  *
  * @return				- 0 or 1
  *
  * @note				- none
  */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> pinNum) & 0x00000001);
	return value;
}

/*****************************************************************
 * @fn					- GPIO_ReadFromInputPort
 *
  * @brief				- Read from entire input port value
  * @param[in]			- GPIO port base address
  * @param[in]
  * @param[in]
  *
  * @return				- GPIO port input value -> return 16-bit
  *
  * @note				- none
  */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}

/*****************************************************************
 * @fn					- GPIO_WriteToOutputPin
 *
  * @brief				- Write a value to an output pin
  * @param[in]			- GPIO port base address
  * @param[in]			- pin number
  * @param[in]			- GPIO_PIN_SET or GPIO_PIN_RESET macros
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum, uint8_t value)
{
	if(value == GPIO_PIN_SET){
		// write 1 to the output data register at the bit corresponding to the pin number
		pGPIOx->ODR |= ( 1 << pinNum);
	} else {
		// write 0
		pGPIOx->ODR &= ~( 1 << pinNum);
	}
}

/*****************************************************************
 * @fn					- GPIO_WriteToOutputPort
 *
  * @brief				- write the valur to the output port
  * @param[in]			- GPIO port base address
  * @param[in]			- 16-bit value to write
  * @param[in]
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,  uint16_t value){
		pGPIOx->ODR = value;
}

/*****************************************************************
 * @fn					- GPIO_ToggleOutputPin
 *
  * @brief				- toggles the output state of a pin
  * @param[in]			- GPIO port base address
  * @param[in]			- pin number to toggle
  * @param[in]
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNum)
{
	pGPIOx->ODR ^= (1 << pinNum);
//	pGPIOx->ODR = pGPIOx->ODR ^ (1 << pinNum);
}

/*
 * 	IRQ Configuration and ISR handling
 */

/*****************************************************************
 * @fn					- GPIO_IRQConfig
 *
  * @brief				- Configure GPIO interrupt setting
  * @param[in]			- IRQ number
  * @param[in]			- Priority level
  * @param[in]			- ENABLE or DISABLE macros
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI)
{

}

/*****************************************************************
 * @fn					- GPIO_IRQConfig
 *
  * @brief
  * @param[in]			-
  * @param[in]
  * @param[in]
  *
  * @return				- none
  *
  * @note				- none
  */
void GPIO_IRQHandling(uint8_t pinNum){

}
