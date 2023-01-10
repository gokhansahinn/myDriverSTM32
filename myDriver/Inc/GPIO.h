/*
 * GPIO.h
 *
 *  Created on: Dec 15, 2022
 *      Author: gokhan.sahin
 */
/*Include Function Prototype*/

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f407xx.h"

/*
 *
 * @def_group GPIO_Pins,
 *
 * */
#define GPIO_PIN_0				(uint16_t)(0x0001)//0000 0000 0000 0001		/*!<GPIO Pin 0 Selected		*/
#define GPIO_PIN_1				(uint16_t)(0x0002)//0000 0000 0000 0010		/*!<GPIO Pin 1 Selected		*/
#define GPIO_PIN_2				(uint16_t)(0x0004)//0000 0000 0000 0100		/*!<GPIO Pin 2 Selected		*/
#define GPIO_PIN_3				(uint16_t)(0x0008)//0000 0000 0000 1000		/*!<GPIO Pin 3 Selected		*/
#define GPIO_PIN_4				(uint16_t)(0x0010)//0000 0000 0001 0000		/*!<GPIO Pin 4 Selected		*/
#define GPIO_PIN_5				(uint16_t)(0x0020)//0000 0000 0010 0000		/*!<GPIO Pin 5 Selected		*/
#define GPIO_PIN_6				(uint16_t)(0x0040)//0000 0000 0100 0000		/*!<GPIO Pin 6 Selected		*/
#define GPIO_PIN_7				(uint16_t)(0x0080)//0000 0000 1000 0000		/*!<GPIO Pin 7 Selected		*/
#define GPIO_PIN_8				(uint16_t)(0x0100)//0000 0001 0000 0000		/*!<GPIO Pin 8 Selected		*/
#define GPIO_PIN_9				(uint16_t)(0x0200)//0000 0010 0000 0000		/*!<GPIO Pin 9 Selected		*/
#define GPIO_PIN_10				(uint16_t)(0x0400)//0000 0100 0000 0000		/*!<GPIO Pin 10 Selected	*/
#define GPIO_PIN_11				(uint16_t)(0x0800)//0000 1000 0000 0000		/*!<GPIO Pin 11 Selected	*/
#define GPIO_PIN_12				(uint16_t)(0x1000)//0001 0000 0000 0000		/*!<GPIO Pin 12 Selected	*/
#define GPIO_PIN_13				(uint16_t)(0x2000)//0010 0000 0000 0000		/*!<GPIO Pin 13 Selected	*/
#define GPIO_PIN_14				(uint16_t)(0x4000)//0100 0000 0000 0000		/*!<GPIO Pin 14 Selected	*/
#define GPIO_PIN_15				(uint16_t)(0x8000)//1000 0000 0000 0000		/*!<GPIO Pin 15 Selected	*/
#define GPIO_PIN_ALL			(uint16_t)(0xFFFF)//1111 1111 1111 1111		/*!<GPIO Pin ALL Selected	*/



/*
 *
 * @def_group GPIO_Modes,
 *
 * */

#define GPIO_MODE_INPUT 				(0X0U)
#define	GPIO_MODE_OUTPUT				(0X1U)
#define GPIO_MODE_AF					(0X2U)
#define GPIO_MODE_ANALOG				(0X3U)


/*
 *
 * @def_group GPIO_OTYPE,
 *
 * */
#define GPIO_OTYPE_PUSH_PULL  			(0X0U)
#define GPIO_OTYPE_OPEN_DRAIN  		    (0X1U)

/*
 *
 * @def_group GPIO_OSPEED,
 *
 * */
#define GPIO_OUTPUT_LOW_SPEED			(0X0U)
#define GPIO_OUTPUT_MEDIUM_SPEED		(0X1U)
#define GPIO_OUTPUT_HIGH_SPEED			(0x2U)
#define GPIO_OUTPUT_VERY_HIGH_SPEED		(0X3U)

/*
 *
 * @def_group GPIO_PuPd,
 *
 * */
#define GPIO_PUPD_NOPULL_NOPUSH			(0X0U)
#define GPIO_PUPD_PULLUP				(0X1U)
#define GPIO_PUPD_PULLDOWN				(0X2U)

/*
 *
 * @def_group GPIO_Alternate Function,
 *
 * */

#define GPIO_AF0						(0X0U)
#define GPIO_AF1						(0X1U)
#define GPIO_AF2						(0X2U)
#define GPIO_AF3						(0X3U)
#define GPIO_AF4						(0X4U)
#define GPIO_AF5						(0X5U)
#define GPIO_AF6						(0X6U)
#define GPIO_AF7						(0X7U)
#define GPIO_AF8						(0X8U)
#define GPIO_AF9						(0X9U)
#define GPIO_AF10						(0XAU)
#define GPIO_AF11						(0XBU)
#define GPIO_AF12						(0XCU)
#define GPIO_AF13						(0XDU)
#define GPIO_AF14						(0XEU)
#define GPIO_AF15						(0XFU)










typedef enum
{
	GPIO_PIN_RESET = 0X0,
	GPIO_PIN_SET = !GPIO_PIN_RESET

}GPIO_Pin_State;



typedef struct
{
	uint32_t pinNumber;  /*!>  GPIO Pin Number @def_group GPIO Pins								*/
	uint32_t Mode;		 /*!>  GPIO Mode @def_group GPIO_Modes									*/
	uint32_t Otyte;		 /*!>  GPIO Output Type @def_group GPIO_OTYPE							*/
	uint32_t Speed;		 /*!>  GPIO Output Speed @def_group GPIO_OSPEED							*/
	uint32_t PuPd;		 /*!>  GPIO Pull Up or Pull  @def_group GPIO_PuPd						*/
	uint32_t Alternate;	 /*!>  GPIO GPIO Alternate Function @def_group GPIO_Alternate Function	*/

}GPIO_InitTypeDef_t;


void GPIO_Init(GPIO_TypeDef_t *GPIOx,GPIO_InitTypeDef_t *GPIO_ConfigStruct);
void GPIO_Write_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber,GPIO_Pin_State pinState);
GPIO_Pin_State GPIO_Read_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber);
void GPIO_Locked_Pin(GPIO_TypeDef_t * GPIOx,uint16_t pinNumber);

#endif /* INC_GPIO_H_ */
