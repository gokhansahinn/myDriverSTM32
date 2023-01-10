/*
 * SPI.c
 *
 *  Created on: Dec 27, 2022
 *      Author: gokhan.sahin
 */

#include "SPI.h"

static void SPI_CloseISR_TX(SPI_HandleTypedef_t * SPI_Handle){

	SPI_Handle->Instance->SPI_CR[1] |= ~((0x1) << SPI_CR2_TXEIE);
	SPI_Handle->TxDataSize=0;
	SPI_Handle->pTxDataAddr=NULL;
	SPI_Handle->busStateTx=SPI_BUS_FREE;




}


static SPI_TransmitHelper_16Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->SPI_DR=*((uint16_t *)SPI_Handle->pTxDataAddr);
	SPI_Handle->pTxDataAddr +=sizeof(uint16_t);
	SPI_Handle->TxDataSize -=2;
	if(SPI_Handle->TxDataSize ==0)
	{
		SPI_CloseISR_TX(SPI_Handle);
	}
}

static SPI_TransmitHelper_8Bits(SPI_HandleTypedef_t *SPI_Handle)
{
	SPI_Handle->Instance->SPI_DR=*((uint8_t *)SPI_Handle->pTxDataAddr);
	SPI_Handle->pTxDataAddr +=sizeof(uint8_t);
	SPI_Handle->TxDataSize --;

	if(SPI_Handle->TxDataSize ==0)
	{
		SPI_CloseISR_TX(SPI_Handle);
	}
}
/**
  * @brief SPI_Init, Configure the SPI Peripherals
  * @param  SPI_Handle = User Config Structure
  *
  * @retval None
  */
void SPI_Init(SPI_HandleTypedef_t *SPI_Handle)
{

	uint32_t tempValue=0;

	tempValue=SPI_Handle->Instance->SPI_CR[0];

	tempValue |=(SPI_Handle->Init.BaudRate)|(SPI_Handle->Init.CPHA)|(SPI_Handle->Init.CPOL)|(SPI_Handle->Init.DFF_Format)|(SPI_Handle->Init.Mode)\

				|(SPI_Handle->Init.Frame_Format|(SPI_Handle->Init.BusConfig)|SPI_Handle->Init.SSM_CMD);

	SPI_Handle->Instance->SPI_CR[0]=tempValue;

}

/**
  * @brief SPI_PeripheralCmd, Configure enable and disable for SPI Peripherals
  * @param  SPI_Handle = User Config Structure
  *	@param  Functional_State_t = User Configure Enable or Disable
  * @retval None
  */
void SPI_PeripheralCmd(SPI_HandleTypedef_t *SPI_Handle,Functional_State_t stateOfSPI)
{
	if(stateOfSPI == ENABLE)
	{
		SPI_Handle->Instance->SPI_CR[0]|=(0x1u << SPI_CR1_SPE);
	}
	else
	{
		SPI_Handle->Instance->SPI_CR[0] &= ~(0x1u << SPI_CR1_SPE);


	}

}



void SPI_TransmitData(SPI_HandleTypedef_t * SPI_Handle,uint8_t *qData,uint16_t sizeofData)
{
	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS)
	{
		while(sizeofData >0)
		{
			if(getSPIFlagStatus(SPI_Handle, SPI_TXE))
			{
				SPI_Handle->Instance->SPI_DR =*((uint16_t *)qData);
				qData +=sizeof(uint16_t);
				sizeofData -= 2;
			}
		}
	}
	else
	{
		while(sizeofData >0)
		{
			if(getSPIFlagStatus(SPI_Handle, SPI_TXE))
			{
				SPI_Handle->Instance->SPI_DR = *qData;
				qData += sizeof(uint8_t);
				sizeofData --;

			}
		}
	}
	while(getSPIFlagStatus(SPI_Handle, SPI_BSY));// wait for BUSY FLAG

}
/**
  * @brief SPI_ReceiveData, Receive a data on SPI Peripheral
  * @param  SPI_Handle = User Config Structure
  *	@param  qBuffer = address of Buffer that I keep
  *	@param  sizeofData = Length of your data in byte
  * @retval None
  */

void SPI_ReceiveData(SPI_HandleTypedef_t *SPI_Handle,uint8_t *qBuffer,uint16_t sizeofData)
{
	if(SPI_Handle->Init.Frame_Format==SPI_DFF_16BITS)
	{
		while(sizeofData>0)
		{
			if(getSPIFlagStatus(SPI_Handle, SPI_RXNE))
			{
				*((uint16_t *)qBuffer)=(uint16_t)SPI_Handle->Instance->SPI_DR;
				qBuffer +=sizeof(uint16_t);
				sizeofData -=2;
			}
		}


	}
	else
	{

		while(sizeofData>0)
		{
			if(getSPIFlagStatus(SPI_Handle, SPI_RXNE))
			{
				*qBuffer = (*(__IO uint8_t *)&SPI_Handle->Instance->SPI_DR);
				qBuffer +=sizeof(uint8_t);
				sizeofData --;
			}
		}
	}
}




void SPI_TransmitData_IT(SPI_HandleTypedef_t *SPI_Handle,uint8_t *qData,uint16_t sizeofData)
{
	SPI_BusStatus_t busStatusTX= SPI_Handle->busStateTx;

	if(busStatusTX != SPI_BUS_BUSY_TX)
	{
		SPI_Handle->pTxDataAddr=(uint8_t*)qData;
		SPI_Handle->TxDataSize=(uint16_t)sizeofData;
		busStatusTX=SPI_BUS_BUSY_TX;

		if(SPI_Handle->Instance->SPI_CR[0] & ((0x1U) <<SPI_CR1_DFF))
		{
			SPI_Handle->TXISRFunction=SPI_TransmitHelper_16Bits;


		}
		else
		{
			SPI_Handle->TXISRFunction=SPI_TransmitHelper_8Bits;
		}

		//ENABLE TO INTERRUPT SQUENCE;
		SPI_Handle->Instance->SPI_CR[1] |=(0x1U << SPI_CR2_TXEIE);

	}

}

void SPI_InterruptHandler(SPI_HandleTypedef_t *SPI_Handle)
{
	uint8_t interruptSource =0;
	uint8_t interruptFlag=0;

	interruptSource= SPI_Handle->Instance->SPI_CR[1] & (0x1U << SPI_CR2_TXEIE);
	interruptFlag = SPI_Handle->Instance->SPI_SR & (0x1U << SPI_SR_TXE);

	if ((interruptSource != 0) && interruptFlag !=0)
	{
		SPI_Handle->TXISRFunction(SPI_Handle);

	}




}
/**
  * @brief getSPIFlagTXE, Return SPI SR Flag Status
  * @param  SPI_Handle = User Config Structure
  *	@param  SPI_Flag = Flag Name of SR register @def_group  SPI STATUS Register (flags) Positions
  * @retval SPI_FlagStatus_t
  */


SPI_FlagStatus_t getSPIFlagStatus(SPI_HandleTypedef_t * SPI_Handle,uint16_t  SPI_Flag)
{
	return SPI_Handle->Instance->SPI_SR & SPI_Flag ? SPI_FLAG_SET : SPI_FLAG_RESET;
}
