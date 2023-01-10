/*
 * GPIO.c
 *
 *  Created on: Dec 15, 2022
 *      Author: gokhan.sahin
 */

/*Include Function Declaration*/




#include "GPIO.h"




/**
  * @brief GPIO_Init, Configures the port and pin
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  GPIO_InitTypeDef_t = User Config Structures
  * @param  pinState = GPIO_Pin_Set OR GPIO_Pin_Reset
  * @retval None
  */
void GPIO_Init(GPIO_TypeDef_t *GPIOx,GPIO_InitTypeDef_t *GPIO_ConfigStruct)
{
	uint32_t position=0;
	uint32_t fakePosition=0;
	uint32_t lastPosition=0;
	for(position=0; position<16 ; position++)
	{
		fakePosition = (0x1U << position);
		lastPosition = (uint32_t)GPIO_ConfigStruct->pinNumber & fakePosition;
		if(lastPosition == fakePosition)
		{
			/*MODE Configuration*/
			uint32_t tempValue=GPIOx->MODER;
			tempValue &= ~((0x3U) << (position*2));
			tempValue |=(GPIO_ConfigStruct->Mode<<(position*2));
			GPIOx->MODER=tempValue;
			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode==GPIO_MODE_AF)
			{
				/*Output Type Configuration*/
				tempValue=GPIOx->OTYPER;
				tempValue &=~(0x1u << position);
				tempValue |= (GPIO_ConfigStruct->Otyte <<position);
				GPIOx->OTYPER;
				/*Output SPEED Configuration*/
				tempValue =GPIOx->OSPEEDR;
				tempValue &=~((0x3U) << (position*2));
				tempValue |= (GPIO_ConfigStruct->Speed << (position*2));
				GPIOx->OSPEEDR=tempValue;

			}

			/*Alternate Function Configuration*/
			if(GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
			{
				tempValue=GPIOx->AFR[position >> 3U];
				tempValue &=~(0xFU << ((position & (0x7U))*4));
				tempValue |=((GPIO_ConfigStruct->Alternate)<<((position &(0x7U))*4));
				GPIOx->AFR[position >> 3U] |=tempValue;
			}
			/*Pull Up Pull Down Configuration*/
			tempValue= GPIOx->PUPDR;
			tempValue &=~((0x3U) << (position*2));
			tempValue |= (GPIO_ConfigStruct->PuPd << (position*2));
			GPIOx->PUPDR=tempValue;






		}
	}


}
/**
  * @brief GPIO_Write_Pin, makes pin High or Low
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Number 0-15
  * @param  pinState = GPIO_Pin_Set OR GPIO_Pin_Reset
  * @retval None
  */
void GPIO_Write_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber,GPIO_Pin_State pinState)
{
	if(pinState == GPIO_PIN_SET)
	{
		GPIOx->BSRR=pinNumber;
	}
	else
	{
 		GPIOx->BSRR |= ( pinNumber <<16U );
	}

}

/**
  * @brief GPIO_Read_Pin, read data from Pin , return GPIO_PIN_SET OR GPIO_PIN_RESET
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Number 0-15
  * @retval GPIO_Pin_State --> GPIO_PIN_SET OR GPIO_PIN_RESET
  */
GPIO_Pin_State GPIO_Read_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber)
{
	GPIO_Pin_State bitStatus =GPIO_PIN_RESET;
	if((GPIOx->IDR & pinNumber )!= GPIO_PIN_RESET)
	{
		bitStatus=GPIO_PIN_SET;
	}


	return bitStatus;


}

/**
  * @brief GPIO_Lock_Pin, This Function locked 0-15 pin on related Port(A-K)
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Number 0-15
  * @retval None
  */

void GPIO_Locked_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber)
{
	uint32_t tempValue = ( 0x1U << 16 ) | pinNumber;   // LCKR[16]='1' (0x1 << 16) LCKR[15:0]=pinNumber(0000 0000 0000 0001)
	GPIOx->LCKR=tempValue;
	GPIOx->LCKR=pinNumber;							   // LCKR[16]='0'  		   LCKR[15:0]=pinNumber(0000 0000 0000 0001)
	GPIOx->LCKR=tempValue;							   // LCKR[16]='1' (0x1 << 16) LCKR[15:0]=pinNumber(0000 0000 0000 0001)
	tempValue=GPIOx->LCKR;							   // Read LCKR[16] if->LCKR[16]='1' Lock is active,


}
/**
  * @brief GPIO_Toggle_Pin, This function is toggled pin
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Number 0-15
  * @retval None
  */

void GPIO_Toggle_Pin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{

	/*SET TO RESET -> RESET TO SET DEPEND ON PIN NUMBER*/
	uint32_t tempValue= GPIOx->ODR;
	GPIOx->BSRR=(tempValue &pinNumber)<<16U | ((~tempValue) &pinNumber);

}



