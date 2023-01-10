/*
 * EXTI.c
 *
 *  Created on: Dec 19, 2022
 *      Author: gokhan.sahin
 */

#include "EXTI.h"




/**
  * @brief EXTI_Init, for valid GPIO port and Line number
  * @param  EXTI_InitStruct= User config parameters
  *
  * @retval None
  */
void EXTI_Init(EXTI_InitTypedef_t *EXTI_InitStruct)
{
	uint32_t tempValue=0;
	tempValue=(uint32_t)EXTI_BASE_ADDR;
	EXTI->EXTI_IMR &= ~(0x1U <<EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EXTI_EMR &= ~(0x1U <<EXTI_InitStruct->EXTI_LineNumber);

	if(EXTI_InitStruct->EXTI_LineCmd != DISABLE)
	{
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*(__IO uint32_t *)tempValue |=(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		tempValue=(uint32_t)EXTI_BASE_ADDR;
		EXTI->EXTI_RTSR &= ~(0x1U <<EXTI_InitStruct->EXTI_LineNumber);
		EXTI->EXTI_FTSR &= ~(0x1U <<EXTI_InitStruct->EXTI_LineNumber);

		if(EXTI_InitStruct->TriggerSelection==EXTI_TRIGGER_MODE_RF)
		{
			EXTI->EXTI_RTSR |= (0x1U <<EXTI_InitStruct->EXTI_LineNumber);
			EXTI->EXTI_FTSR |= (0x1U <<EXTI_InitStruct->EXTI_LineNumber);

		}
		else
		{
			tempValue +=EXTI_InitStruct->TriggerSelection;
			*(__IO uint32_t*)tempValue |=(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}
	}
	else
	{
		tempValue=(uint32_t)EXTI_BASE_ADDR;
		tempValue+=EXTI_InitStruct->EXTI_Mode;
		*(__IO uint32_t*)tempValue &= ~(0x1u << EXTI_InitStruct->EXTI_LineNumber);

	}

}




/**
  * @brief EXTI_LineConfig, Configures the port and pin for SYSCFG
  * @param  PinSource= Port Value A-I @def_group Port_Values
  *
  * @param  EXTI_LineSource = pin number and line numbers @def_group EXTI_Line_Values
  * @retval None
  */
void EXTI_LineConfig( uint8_t PinSource,uint8_t EXTI_LineSource)
{
	uint32_t tempValue;


	tempValue = SYSCFG->SYSCFG_EXTICR[EXTI_LineSource>>2U];
	tempValue &=~(0xFU << (4*(EXTI_LineSource&0x3))); //CLEAR PROCESS DONE!
	tempValue= (PinSource << (4*(EXTI_LineSource&0x3)));
	SYSCFG->SYSCFG_EXTICR[EXTI_LineSource>>2U]=tempValue;


}
/**
  * @brief NVIC_EnableInterrupt, NVIC Register Config.
  * @param uint8_t IRQNumber=IRQ Number for interrupt lines
  *
  * @retval None
  */
void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber)
{

	uint32_t tempValue=0;
	tempValue=*((IRQNumber >> 5U)+ NVIC_ISER);
	tempValue &=~(0x1U << (IRQNumber & 0x1F));
	tempValue |= (0x1U << (IRQNumber & 0x1F));
	*((IRQNumber >> 5U)+ NVIC_ISER)=tempValue;

}

















