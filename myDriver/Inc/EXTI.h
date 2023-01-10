/*
 * EXTI.h
 *
 *  Created on: Dec 19, 2022
 *      Author: gokhan.sahin
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f407xx.h"



/*
 *
 * @def_group PORT_Values,
 *
 * */
#define EXTI_PortSource_GPIOA 			((uint8_t)(0x0))
#define EXTI_PortSource_GPIOB 			((uint8_t)(0x1))
#define EXTI_PortSource_GPIOC 			((uint8_t)(0x2))
#define EXTI_PortSource_GPIOD 			((uint8_t)(0x3))
#define EXTI_PortSource_GPIOE 			((uint8_t)(0x4))
#define EXTI_PortSource_GPIOF 			((uint8_t)(0x5))
#define EXTI_PortSource_GPIOG 			((uint8_t)(0x6))
#define EXTI_PortSource_GPIOH 			((uint8_t)(0x7))
/*
 *
 * @def_group EXTI_Line_Values,
 *
 * */
#define EXTI_LineSource_0				((uint8_t)(0x0))
#define EXTI_LineSource_1				((uint8_t)(0x1))
#define EXTI_LineSource_2				((uint8_t)(0x2))
#define EXTI_LineSource_3				((uint8_t)(0x3))
#define EXTI_LineSource_4				((uint8_t)(0x4))
#define EXTI_LineSource_5				((uint8_t)(0x5))
#define EXTI_LineSource_6				((uint8_t)(0x6))
#define EXTI_LineSource_7				((uint8_t)(0x7))
#define EXTI_LineSource_8				((uint8_t)(0x8))
#define EXTI_LineSource_9				((uint8_t)(0x9))
#define EXTI_LineSource_10				((uint8_t)(0xA))
#define EXTI_LineSource_11				((uint8_t)(0xB))
#define EXTI_LineSource_12				((uint8_t)(0xC))
#define EXTI_LineSource_13				((uint8_t)(0xD))
#define EXTI_LineSource_14				((uint8_t)(0xE))
#define EXTI_LineSource_15				((uint8_t)(0xF))

/*
 * @def_group EXTI_Mode_Values
 *
 * */
#define EXTI_MODE_INTERRUPT 			(0X00U)
#define EXTI_MODE_EVENT 				(0X04U)
/*
 * That struct for Init parametre that get from user
 * */

/*
 * @def_group EXTI_TRIGGER_TYPE
 * */

#define EXTI_TRIGGER_MODE_RISING		(0X08U)
#define EXTI_TRIGGER_MODE_FALLING		(0X0CU)
#define EXTI_TRIGGER_MODE_RF			(0X10U)






typedef struct
{

	uint8_t EXTI_LineNumber;			/*!> EXTI Line NUmber for valid GPIo pin @def_group EXTI_Line_Values 	*/
	uint8_t TriggerSelection;			/*!> EXTI Trigger Selection @def_group EXTI_TRIGGER_TYPE 			 	*/
	uint8_t EXTI_Mode;					/*!< EXTI Mode Values @def_group EXTI_Mode_Values						*/
	Functional_State_t EXTI_LineCmd;	/*!> Unmask or Mask for EXTI Mask Register							 	*/

}EXTI_InitTypedef_t;




























void EXTI_LineConfig( uint8_t PinSource,uint8_t EXTI_LineSource);
void EXTI_Init(EXTI_InitTypedef_t *EXTI_InitStruct);
void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber);
#endif /* INC_EXTI_H_ */
