/*
 * SPI.h
 *
 *  Created on: Dec 27, 2022
 *      Author: gokhan.sahin
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_


#include "stm32f407xx.h"




typedef enum
{

	SPI_BUS_FREE=0x0U,
	SPI_BUS_BUSY_TX=0x1U,
	SPI_BUS_BUSY_RX=0x2U

}SPI_BusStatus_t;
/*
 *
 * @def_group SPI_BaudRates
 *
 * */
#define SPI_BAUDRATE_DIV2 				((uint32_t)0X00000000)
#define SPI_BAUDRATE_DIV4 				((uint32_t)0X00000008)  //0000 0000 0000 0000 0000 0000 0000 1000
#define SPI_BAUDRATE_DIV8 				((uint32_t)0X00000010)	//0000 0000 0000 0000 0000 0000 0001 0000
#define SPI_BAUDRATE_DIV16 				((uint32_t)0X00000018)	//0000 0000 0000 0000 0000 0000 0001 1000
#define SPI_BAUDRATE_DIV32 				((uint32_t)0X00000020)	//0000 0000 0000 0000 0000 0000 0010 0000
#define SPI_BAUDRATE_DIV64 				((uint32_t)0X00000028)	//0000 0000 0000 0000 0000 0000 0010 1000
#define SPI_BAUDRATE_DIV128 			((uint32_t)0X00000030)	//0000 0000 0000 0000 0000 0000 0011 0000
#define SPI_BAUDRATE_DIV256 			((uint32_t)0X00000038)	//0000 0000 0000 0000 0000 0000 0011 1000

/*
 *
 * @def_group CPHA Macros
 *
 * */

#define SPI_CPHA_FIRST					((uint32_t)0X00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_CPHA_SECOND					((uint32_t)0X00000001)	//0000 0000 0000 0000 0000 0000 0000 0001



/*
 *
 * @def_group CPOL Macros
 *
 * */


#define SPI_CPOL_LOW					((uint32_t)0X00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_CPOL_HIGH					((uint32_t)0X00000002)	//0000 0000 0000 0000 0000 0000 0000 0010

/*
 *
 * @def_group SPI_DFF_Formats
 *
 * */

#define SPI_DFF_8BITS					((uint32_t)0x00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_DFF_16BITS					((uint32_t)0x00000800)	//0000 0000 0000 0000 0000 1000 0000 0000

/*
 *
 * @def_group SPI_MODES
 *
 * */
#define SPI_MODE_SLAVE					((uint32_t)0x00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_MODE_MASTER					((uint32_t)0x00000004)	//0000 0000 0000 0000 0000 0000 0000 0100

/*
 *
 * @def_group SPI_Frame_Format
 *
 * */

#define SPI_FRAMEFORMANT_MSB			((uint32_t)0x00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_FRAMEFORMAT_LSB				((uint32_t)0x00000080)	//0000 0000 0000 0000 0000 0000 1000 0000

/*
 *
 *@def_group SPI_BusConfigValues
 *
 * */


#define SPI_BUS_FullDuplex				((uint32_t)0x00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_BUS_ReceiveOnly				((uint32_t)0x00000400)	//0000 0000 0000 0000 0000 0100 0000 0000
#define SPI_BUS_HalfDuplex_T			((uint32_t)0x0000C000)	//0000 0000 0000 0000 1100 0000 0000 0000
#define SPI_BUS_HalfDuplex_R			((uint32_t)0x00008000)	//0000 0000 0000 0000 1000 0000 0000 0000

/*
 *
 * @def_group SPI_SSM_VALUES
 *
 * */

#define SPI_SSM_DISABLE					((uint32_t)0x00000000)	//0000 0000 0000 0000 0000 0000 0000 0000
#define SPI_SSM_ENABLE					((uint32_t)0x00000300)	//0000 0000 0000 0000 0000 0011 0000 0000


/*
 *
 * @def_group define macros SPI STATUS Register (flags) Position
 *
 * */

#define SPI_RXNE						 (1U << SPI_SR_RXNE)//0000 0000 0000 0001
#define SPI_TXE							 (1U << SPI_SR_TXE)//0000 0000 0000 0010
#define SPI_BSY							 (1U << SPI_SR_BSY)//0000 0000 1000 0000


typedef enum
{

	SPI_FLAG_RESET = 0X0,
	SPI_FLAG_SET=!SPI_FLAG_RESET,
}SPI_FlagStatus_t;




typedef struct
{
	uint32_t Mode;					 /*!>  SPI Mode is Master or Slave Configurations @def_group SPI_MODES*/
	uint32_t CPHA;					 /*!>  SPI Clock Phase Configurations @def_group CHPA Macros*/
	uint32_t CPOL;					 /*!>  SPI Clock Polarity Configurations @def_group CPOL Macros*/
	uint32_t BaudRate;				 /*!>  SPI BAUDRATE @def_group SPI_BaudRates*/
	uint32_t SSM_CMD;				 /*!>  SPI SSM VALUES @def_group SPI_SSM_VALUES*/
	uint32_t DFF_Format;			 /*!>  SPI DFF_Format @def_group SPI_DFF_Format*/
	uint32_t BusConfig;				 /*!>  SPI Bus Config Values @def_group SPI_BusConfigValues*/
	uint32_t Frame_Format;			 /*!>  SPI Frame_Format @def_group SPI_Frame_Format*/

}SPI_InitTypeDef_t;


typedef struct SPI_HandleType_t{

	SPI_TypeDef_t * Instance; // this keep for SPI Address
	SPI_InitTypeDef_t Init;
	uint8_t * pTxDataAddr;
	uint16_t TxDataSize;
	uint16_t busStateTx;
	void (*TXISRFunction)(struct SPI_HandleType_t *SPI_Handle);  //function pointer

}SPI_HandleTypedef_t;


void SPI_Init(SPI_HandleTypedef_t *SPI_Handle);
void SPI_PeripheralCmd(SPI_HandleTypedef_t *SPI_Handle,Functional_State_t stateOfSPI);
void SPI_TransmitData(SPI_HandleTypedef_t * SPI_Handle,uint8_t *qData,uint16_t sizeofData);
void SPI_ReceiveData(SPI_HandleTypedef_t *SPI_Handle,uint8_t *qBuffer,uint16_t sizeofData);
void SPI_TransmitData_IT(SPI_HandleTypedef_t *SPI_Handle,uint8_t *qData,uint16_t sizeofData);
void SPI_InterruptHandler(SPI_HandleTypedef_t *SPI_Handle);
SPI_FlagStatus_t getSPIFlagStatus(SPI_HandleTypedef_t * SPI_Handle,uint16_t  SPI_Flag);
#endif /* INC_SPI_H_ */
