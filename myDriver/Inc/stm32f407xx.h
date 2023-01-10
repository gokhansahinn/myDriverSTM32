/*
 * stm32f407xx.h
 *
 *  Created on: Dec 13, 2022
 *      Author: gokhan.sahin
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define __IO					volatile
#define SET_BIT(REG,BIT)        (	(REG) |= (BIT)	)
#define CLEAR_BIT(REG,BIT)		(   (REG) &= ~(BIT)	)
#define READ_BIT(REG,BIT)		(   (REG) &   (BIT)	)
#define UNUSED(x)				(void)x



/*
 *
 * Microprocessor Defines
 *
 * */

#define NVIC_ISER				((uint32_t*)(0xE000E100)	)




typedef enum{

	DISABLE=0X0U,
	ENABLE=!DISABLE,


}Functional_State_t;
/*
 * IRQ Numbers of MCU == Vector Table
 *
 */

typedef enum
{
	EXTI0_IRQNumber=6,
	EXTI1_IRQNumber=7,
	EXTI2_IRQNumber=8,
	EXTI3_IRQNumber=9,
	EXTI4_IRQNumber=10,
	EXTI9_5_IRQNumber=23,
	SPI1_IRQNumber=35



}IRQNumber_TypeDef_t;




/*
 * Memory Base Address
 *
 *
 */
#define FLASH_BASE_ADDR					(0x08000000UL)	/*Flash Memory Base Address (up to 1MB)                            */
#define SRAM1_BASE_ADDR					(0x20000000UL) /*SRAM1 Memory Base Address (up to 112KB) Main internal memory     */
#define SRAM2_BASE_ADDR					(0x2001C000UL) /*SRAM2 Memory Base Address (up to 16KB) Auxiliary internal memory */


/*
 * Peripheral Bus Base Address
 *
 * */

#define PERIPH_BASE_ADDR					(0x40000000UL) /*Base Address for All Peripheral            */
#define APB1_BASE_ADDR						PERIPH_BASE_ADDR /*APB1 BUS DOMAIN BASE ADDRESS             */
#define APB2_BASE_ADDR						(PERIPH_BASE_ADDR+0x10000UL) /*APB2 BUS DOMAIN BASE ADDRESS */
#define AHB1_BASE_ADDR						(PERIPH_BASE_ADDR+0x20000UL) /*AHB1 BUS DOMAIN BASE ADDRESS */
#define AHB2_BASE_ADDR						(PERIPH_BASE_ADDR+0X10000000UL)/*AHB2 BUS DOMAIN BASE ADDRESS*/


/*
 *
 * APB1 Peripheral Base Address
 *
 * */

#define TIM2_BASE_ADDR						(APB1_BASE_ADDR + 0x0000UL)	/*Timer 2 Peripheral Base Address*/
#define TIM3_BASE_ADDR						(APB1_BASE_ADDR + 0x0400UL) /*Timer 3 Peripheral Base Address*/
#define TIM4_BASE_ADDR						(APB1_BASE_ADDR + 0X0800UL) /*Timer 4 Peripheral Base Address*/

#define SPI2_BASE_ADDR						(APB1_BASE_ADDR + 0x3800UL) /*SPI2/I2S3 Peripheral Base Address   */
#define SPI3_BASE_ADDR						(APB1_BASE_ADDR + 0x3C00UL) /*SPI3/I2S2 Peripheral Base Address*/

#define USART2_BASE_ADDR					(APB1_BASE_ADDR + 0x4400UL) /*USART2 Peripheral Base Address*/
#define USART3_BASE_ADDR					(APB1_BASE_ADDR + 0x4800UL) /*USART3 Peripheral Base Address*/
#define USART4_BASE_ADDR					(APB1_BASE_ADDR + 0x4C00UL) /*USART4 Peripheral Base Address*/
#define USART5_BASE_ADDR					(APB1_BASE_ADDR + 0x5000UL) /*USART5 Peripheral Base Address*/


#define I2C1_BASE_ADDR						(APB1_BASE_ADDR + 0x5400UL) /*I2C1 Peripheral Base Address*/
#define I2C2_BASE_ADDR						(APB1_BASE_ADDR + 0x5800UL) /*I2C2 Peripheral Base Address*/
#define I2C3_BASE_ADDR						(APB1_BASE_ADDR + 0X5C00UL) /*I2C3 Peripheral Base Address*/

/*
 *
 * APB2 Peripheral Base Address
 *
 * */

#define TIM1_BASE_ADDR						(APB2_BASE_ADDR + 0x0000UL)  /*Timer 1 Peripheral Base Address  */
#define TIM8_BASE_ADDR						(APB2_BASE_ADDR + 0x0400UL)  /*Timer 8 Peripheral Base Address  */

#define USART1_BASE_ADDR					(APB2_BASE_ADDR + 0x1000UL)  /*USART1 Peripheral Base Address   */
#define USART6_BASE_ADDR					(APB2_BASE_ADDR + 0x1400UL)  /*USART6 Peripheral Base Address   */

#define SPI1_BASE_ADDR						(APB2_BASE_ADDR + 0x3000UL)  /*SPI1 Peripheral Base Address     */
#define SPI4_BASE_ADDR						(APB2_BASE_ADDR + 0x3400UL)  /*SPI4 Peripheral Base Address     */

#define SYSCFG_BASE_ADDR					(APB2_BASE_ADDR + 0x3800UL)  /*SYSCFG Peripheral Base Address   */

#define EXTI_BASE_ADDR						(APB2_BASE_ADDR + 0x3C00UL)  /*EXTI Peripheral Base Address     */



/*
 *
 * AHB1 Peripheral Base Address
 *
 * */

#define GPIO_A_BASE_ADDR					(AHB1_BASE_ADDR+0x0000UL)    /*GPIO_A Peripheral Base Address   */
#define GPIO_B_BASE_ADDR					(AHB1_BASE_ADDR+0x0400UL)    /*GPIO_B Peripheral Base Address   */
#define GPIO_C_BASE_ADDR					(AHB1_BASE_ADDR+0x0800UL)    /*GPIO_C Peripheral Base Address   */
#define GPIO_D_BASE_ADDR					(AHB1_BASE_ADDR+0x0C00UL)    /*GPIO_D Peripheral Base Address   */
#define GPIO_E_BASE_ADDR					(AHB1_BASE_ADDR+0x1000UL)    /*GPIO_E Peripheral Base Address   */
#define GPIO_F_BASE_ADDR					(AHB1_BASE_ADDR+0x1400UL)    /*GPIO_F Peripheral Base Address   */
#define GPIO_G_BASE_ADDR					(AHB1_BASE_ADDR+0x1800UL)    /*GPIO_G Peripheral Base Address   */
#define GPIO_H_BASE_ADDR					(AHB1_BASE_ADDR+0x1C00UL)    /*GPIO_H Peripheral Base Address   */
#define GPIO_I_BASE_ADDR					(AHB1_BASE_ADDR+0x2000UL)    /*GPIO_I Peripheral Base Address   */
#define GPIO_J_BASE_ADDR					(AHB1_BASE_ADDR+0x2400UL)    /*GPIO_J Peripheral Base Address   */
#define GPIO_K_BASE_ADDR					(AHB1_BASE_ADDR+0x2800UL)    /*GPIO_K Peripheral Base Address   */

#define CRC_BASE_ADDR						(AHB1_BASE_ADDR+0x3000UL)	 /*CRC Peripheral Base Address   	*/

#define RCC_BASE_ADDR						(AHB1_BASE_ADDR+0x3800UL)	 /*RCC Peripheral Base Address   */



/*
 *
 * Peripheral Structure Definitions
 *
 *
 * */
typedef struct
{

	__IO uint32_t MODER;    /*!< GPIO Mode Register						Address Offset =0x0000	*/
	__IO uint32_t OTYPER;   /*!< GPIO Output Type Register				Address Offset =0x0004	*/
	__IO uint32_t OSPEEDR;  /*!< GPIO Output Speed Register				Address Offset =0x0008	*/
	__IO uint32_t PUPDR;    /*!< GPIO Pull-up Pull-Down Register		Address Offset =0x000C	*/
	__IO uint32_t IDR;      /*!< GPIO Input Data Register				Address Offset =0x0010	*/
	__IO uint32_t ODR;      /*!< GPIO Output Data Register				Address Offset =0x0014	*/
	__IO uint32_t BSRR;     /*!< GPIO Bit Set/Reset Register			Address Offset =0x0018	*/
	__IO uint32_t LCKR;		/*!< GPIO Configuration Lock Register		Address Offset =0x001C	*/
	__IO uint32_t AFR[2];   /*!< GPIO Alternate Function Register(L)	Address Offset =0x0020	*/
							/*!< GPIO Alternate Function Register(H)	Address Offset =0x0024	*/

}GPIO_TypeDef_t;

typedef struct
{
	__IO uint32_t CR;			/*!< RCC Clock Control Register											Address Offset =0x0000	*/
	__IO uint32_t PLLCFGR;		/*!< RCC PLL Configuration Register										Address Offset =0x0004	*/
	__IO uint32_t CFGR;			/*!< RCC Clock Configuration Register									Address Offset =0x0008	*/
	__IO uint32_t CIR;			/*!< RCC Clock Interrupt Register										Address Offset =0x000C	*/
	__IO uint32_t AHB1RSTR;		/*!< RCC AHB1 Peripheral Reset Register									Address Offset =0x0010	*/
	__IO uint32_t AHB2RSTR;		/*!< RCC AHB2 Peripheral Reset Register									Address Offset =0x0014	*/
	__IO uint32_t AHB3RSTR;		/*!< RCC AHB3 Peripheral Reset Register									Address Offset =0x0018	*/
	__IO uint32_t RESERVERD0;   /*!< RCC REVERSED0 AREA													Address Offset =0x001C	*/
	__IO uint32_t APB1RSTR;		/*!< RCC APB1 Peripheral Reset Register									Address Offset =0x0020	*/
	__IO uint32_t APB2RSTR;		/*!< RCC APB2 Peripheral Reset Register									Address Offset =0x0024	*/
	__IO uint32_t RESERVERD1;	/*!< RCC REVERSED1 AREA													Address Offset =0x0028	*/
	__IO uint32_t RESERVERD2;	/*!< RCC REVERSED2 AREA													Address Offset =0x002C	*/
	__IO uint32_t AHB1ENR;		/*!< RCC AHB1 Peripheral Clock Enable Register							Address Offset =0x0030	*/
	__IO uint32_t AHB2ENR;		/*!< RCC AHB2 Peripheral Clock Enable Register							Address Offset =0x0034	*/
	__IO uint32_t AHB3ENR;		/*!< RCC AHB3 Peripheral Clock Enable Register							Address Offset =0x0038	*/
	__IO uint32_t RESERVERD3;	/*!< RCC REVERSED3 AREA													Address Offset =0x003C	*/
	__IO uint32_t APB1ENR;		/*!< RCC APB1 Peripheral Clock Enable Register							Address Offset =0x0040	*/
	__IO uint32_t APB2ENR;		/*!< RCC APB2 Peripheral Clock Enable Register							Address Offset =0x0044	*/
	__IO uint32_t RESERVERD4;	/*!< RCC REVERSED4 AREA													Address Offset =0x0048	*/
	__IO uint32_t RESERVERD5;	/*!< RCC REVERSED5 AREA													Address Offset =0x004C	*/
	__IO uint32_t AHB1LPENR;	/*!< RCC AHB1 Peripheral Clock Enable in Low Power Mode Register		Address Offset =0x0050	*/
	__IO uint32_t AHB2LPENR;	/*!< RCC AHB2 Peripheral Clock Enable in Low Power Mode Register		Address Offset =0x0054	*/
	__IO uint32_t AHB3LPENR;	/*!< RCC AHB3 Peripheral Clock Enable in Low Power Mode Register		Address Offset =0x0058	*/
	__IO uint32_t RESERVERD6;	/*!< RCC REVERSED6 AREA													Address Offset =0x005C	*/
	__IO uint32_t APB1LPENR;	/*!< RCC AHP1 Peripheral Clock Enable in Low Power Mode Register		Address Offset =0x0060	*/
	__IO uint32_t APB2LPENR;	/*!< RCC AHP2 Peripheral Clock Enable in Low Power Mode Register		Address Offset =0x0064	*/
	__IO uint32_t RESERVERD7;	/*!< RCC REVERSED7 AREA													Address Offset =0x0068	*/
	__IO uint32_t RESERVERD8;	/*!< RCC REVERSED8 AREA													Address Offset =0x006C	*/
	__IO uint32_t BDCR;			/*!< RCC Back Domain Control Register									Address Offset =0x0070	*/
	__IO uint32_t CSR;			/*!< RCC Clock Control & Status Register								Address Offset =0x0074	*/
	__IO uint32_t RESERVERD9;	/*!< RCC REVERSED9 AREA													Address Offset =0x0078	*/
	__IO uint32_t RESERVERD10;	/*!< RCC REVERSED10 AREA												Address Offset =0x007C	*/
	__IO uint32_t SSCGR;		/*!< RCC Spread Spectrum Clock Generation Register						Address Offset =0x0080	*/
	__IO uint32_t PLLI2SCFGR;	/*!< RCC PLLIS2 Configuration Register									Address Offset =0x0084	*/



}RCC_TypeDef_t;




typedef struct
{
	__IO uint32_t SYSCFG_MEMRMP;	/*!< SYSCFG Memory Remap Register										Address Offset =0x0000	*/
	__IO uint32_t SYSCFG_PMC;		/*!< SYSCFG Peripheral Mode Configurations Register						Address Offset =0x0004	*/
	__IO uint32_t SYSCFG_EXTICR[4]; /*!< SYSCFG External Interrupt Configuration Register[0-4]				Address Offset =0x0008	*/
	__IO uint32_t SYSCFG_CMPCR;		/*!< SYSCFG Compensation Cell Control Register							Address Offset =0x0020	*/

}SYSCFG_TypeDef_t;


typedef struct
{
	__IO uint32_t EXTI_IMR;			/*!< EXTI Interrupt Mask Register										Address Offset =0x0000	*/
	__IO uint32_t EXTI_EMR;			/*!< EXTI Event  	Mask Register										Address Offset =0x0004	*/
	__IO uint32_t EXTI_RTSR;		/*!< EXTI Rising Trigger Selection Register								Address Offset =0x0008	*/
	__IO uint32_t EXTI_FTSR;		/*!< EXTI Falling Trigger Selection Register							Address Offset =0x000C	*/
	__IO uint32_t EXTI_SWIER;		/*!< EXTI Software Interrupt Event Register								Address Offset =0x0010	*/
	__IO uint32_t EXTI_PR;			/*!< EXTI Pending Register												Address Offset =0x0014	*/


}EXTI_TypeDef_t;


typedef struct
{

	__IO uint32_t SPI_CR[2];		/*!< SPI Control Register												Address Offset =0x0000	*/
	__IO uint32_t SPI_SR;			/*!< SPI Status Register												Address Offset =0x0008	*/
	__IO uint32_t SPI_DR;			/*!< SPI Data Register													Address Offset =0x000C	*/
	__IO uint32_t SPI_CRCPR;		/*!< SPI CRC Polynomial Register(Not use in I2S Mode)					Address Offset =0x0010	*/
	__IO uint32_t SPI_RXCRCR;		/*!< SPI RX CRC Register(Not use in I2S Mode)							Address Offset =0x0014	*/
	__IO uint32_t SPI_TXCRCR;		/*!< SPI TX CRC Register(Not use in I2S Mode)							Address Offset =0x0018	*/
	__IO uint32_t SPI_I2SCFGR;		/*!< SPI I2S Configuration Register										Address Offset =0x001C	*/
	__IO uint32_t SPI_I2SPR;		/*!< SPI I2S Prescaler Register											Address Offset =0x0020	*/

}SPI_TypeDef_t;

/*Base Address Definitions of ports */

#define GPIOA									((GPIO_TypeDef_t *)(GPIO_A_BASE_ADDR	))
#define GPIOB									((GPIO_TypeDef_t *)(GPIO_B_BASE_ADDR	))
#define GPIOC									((GPIO_TypeDef_t *)(GPIO_C_BASE_ADDR	))
#define GPIOD									((GPIO_TypeDef_t *)(GPIO_D_BASE_ADDR	))
#define GPIOE									((GPIO_TypeDef_t *)(GPIO_E_BASE_ADDR	))
#define GPIOF									((GPIO_TypeDef_t *)(GPIO_F_BASE_ADDR	))
#define GPIOG									((GPIO_TypeDef_t *)(GPIO_G_BASE_ADDR	))
#define GPIOH									((GPIO_TypeDef_t *)(GPIO_H_BASE_ADDR	))
#define GPIOI									((GPIO_TypeDef_t *)(GPIO_I_BASE_ADDR	))
#define GPIOJ									((GPIO_TypeDef_t *)(GPIO_J_BASE_ADDR	))
#define GPIOK									((GPIO_TypeDef_t *)(GPIO_K_BASE_ADDR	))

#define RCC										((RCC_TypeDef_t *)(RCC_BASE_ADDR		))

#define SYSCFG									((SYSCFG_TypeDef_t*)(SYSCFG_BASE_ADDR	))

#define EXTI									((EXTI_TypeDef_t *)(EXTI_BASE_ADDR		))

#define SPI1									((SPI_TypeDef_t *)(SPI1_BASE_ADDR		))
#define SPI2									((SPI_TypeDef_t *)(SPI2_BASE_ADDR		))
#define SPI3									((SPI_TypeDef_t *)(SPI3_BASE_ADDR		))
#define SPI4									((SPI_TypeDef_t *)(SPI4_BASE_ADDR		))

/*BIT DEFITIONS RCC_AHB1ENR FOR GPIOA*/
#define RCC_AHB1ENR_GPIOA						(0U)									/*RCC AHB1ENR Register GPIOAEN Position 	*/
#define RCC_AHB1ENR_GPIOA_Msk					(0x1 << RCC_AHB1ENR_GPIOA )				/*RCC AHB1ENR Register GPIOAEN Mask 		*/
#define RCC_AHB1ENR_GPIOAEN						RCC_AHB1ENR_GPIOA_Msk  					/*RCC AHB1ENR Register GPIOAEN Macro 		*/
/*BIT DEFITIONS RCC_AHB1ENR FOR GPIOB*/
#define RCC_AHB1ENR_GPIOB						(1U)									/*RCC AHB1ENR Register GPIOBEN Position		*/
#define RCC_AHB1ENR_GPIOB_Mask					(0x1 << RCC_AHB1ENR_GPIOB)				/*RCC AHB1ENR Register GPIOBEN MASK			*/
#define RCC_AHB1ENR_GPIOBEN						RCC_AHB1ENR_GPIOB_Mask					/*RCC AHB1ENR Register GPIOBEN MACRO		*/
/*BIT DEFITIONS RCC_AHB1ENR FOR GPIOC*/
#define RCC_AHB1ENR_GPIOC						(2U)									/*RCC AHB1ENR Register GPIOCEN Position		*/
#define RCC_AHB1ENR_GPIOC_Msk					(0x1  << RCC_AHB1ENR_GPIOC)				/*RCC AHB1ENR Register GPIOCEN MASK			*/
#define RCC_AHB1ENR_GPIOCEN						RCC_AHB1ENR_GPIOC_Msk					/*RCC AHB1ENR Register GPIOCEN MACRO		*/
/*BIT DEFITIONS RCC_AHB1ENR FOR GPIOC*/
#define RCC_AHB1ENR_GPIOD						(3U)									/*RCC AHB1ENR Register GPIODEN Position		*/
#define RCC_AHB1ENR_GPIOD_Msk					(0x1  << RCC_AHB1ENR_GPIOD)				/*RCC AHB1ENR Register GPIODEN MASK			*/
#define RCC_AHB1ENR_GPIODEN						RCC_AHB1ENR_GPIOD_Msk					/*RCC AHB1ENR Register GPIODEN MACRO		*/
/*BIT DEFITIONS RCC_APB2 FOR SYSCFG*/
#define RCC_APB2ENR_SYSCFG						(14U)									/*RCC APB2ENR Register SYSCGFEN Position	*/
#define RCC_APB2ENR_SYSCFG_Msk					(0x1  << RCC_APB2ENR_SYSCFG)			/*RCC APB2ENR Register SYSCGFEN MASK		*/
#define RCC_APB2ENR_SYSCFGEN					RCC_APB2ENR_SYSCFG_Msk					/*RCC APB2ENR Register SYSCGFEN MACRO		*/
/*BIT DEFITIONS RCC_APB2 FOR SPI1*/
#define RCC_APB2ENR_SPI1						(12U)									/*RCC APB2ENR Register SPI1 Position		*/
#define RCC_APB2ENR_SPI1_Msk					(0x1  << RCC_APB2ENR_SPI1)				/*RCC APB2ENR Register SPI1EN MASK			*/
#define RCC_APB2ENR_SPI1EN						RCC_APB2ENR_SPI1_Msk					/*RCC APB2ENR Register SPI1EN MACRO			*/
/*BIT DEFITIONS RCC_APB2 FOR SPI4*/
#define RCC_APB2ENR_SPI4						(13U)									/*RCC APB2ENR Register SPI4 Position		*/
#define RCC_APB2ENR_SPI4_Msk					(0x1  << RCC_APB2ENR_SPI4)				/*RCC APB2ENR Register SPI4EN MASK			*/
#define RCC_APB2ENR_SPI4EN						RCC_APB2ENR_SPI4_Msk					/*RCC APB2ENR Register SPI4EN MACRO			*/
/*BIT DEFITIONS RCC_APB1 FOR SPI2*/
#define RCC_APB1ENR_SPI2						(14U)									/*RCC APB1ENR Register SPI2 Position		*/
#define RCC_APB1ENR_SPI2_Msk					(0x1  << RCC_APB1ENR_SPI2)				/*RCC APB1ENR Register SPI2EN MASK			*/
#define RCC_APB1ENR_SPI2EN						RCC_APB1ENR_SPI2_Msk					/*RCC APB1ENR Register SPI2EN MACRO			*/
/*BIT DEFITIONS RCC_APB1 FOR SPI3*/
#define RCC_APB1ENR_SPI3						(15U)									/*RCC APB1ENR Register SPI3 Position		*/
#define RCC_APB1ENR_SPI3_Msk					(0x1  << RCC_APB1ENR_SPI3)				/*RCC APB1ENR Register SPI3EN MASK			*/
#define RCC_APB1ENR_SPI3EN						RCC_APB1ENR_SPI3_Msk					/*RCC APB1ENR Register SPI3EN MACRO			*/
/*BIT DEFINATIONS SPI_CR1*/
#define SPI_CR1_SPE								(6U)									/*SPI CONTROL REGISTER 1 SPI ENABLE BIT		*/
#define SPI_CR2_TXEIE							(7U)									/*SPI CONTROL REGISTER 2 SPI TXEIE			*/
#define SPI_CR1_DFF								(11U)									/*SPI CONTROL REGISTER 1 SPI DFF BIT		*/
/*BIT DEFINATIONS SPI_SR FOR SPI STATUS FLAGS*/
#define SPI_SR_RXNE								(0U)									/*SPI STATUS  REGISTER  SPI RXNE			*/
#define SPI_SR_TXE								(1U)									/*SPI STATUS  REGISTER  SPI TXE				*/
#define SPI_SR_BSY								(7U)									/*SPI STATUS  REGISTER  SPI BUST			*/










#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#endif /* INC_STM32F407XX_H_ */
