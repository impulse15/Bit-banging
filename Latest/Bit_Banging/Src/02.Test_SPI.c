
/*
 * 02.Test_SPI.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Sarang
 */

#include <stdint.h>
#include "G0B1RE.h"
#include "GPIO.h"
#include "SPI.h"
#include <string.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void SPI_Setup(SPI_Handler_t * SPI)
{
	SPI->SPI_Config.Baudrate = SPI_BAUDRATE_DIV2;
	SPI->SPI_Config.CPHA = SPI_CPHA_DI;
	SPI->SPI_Config.CPOL = SPI_CPOL_DI;
	SPI->SPI_Config.DATA_Format = SPI_DATA_FORMAT_MSBF;
	SPI->SPI_Config.DATA_Size = SPI_DATA_Size_8bits;
	SPI->SPI_Config.PIN_CLK = PIN_10;
	SPI->SPI_Config.PIN_MISO = PIN_15;
	SPI->SPI_Config.PIN_MOSI = PIN_5;
	SPI->SPI_Config.PIN_NS = PIN_6;
	SPI->SPI_Config.pPort = GPIOA;
	SPI->SPI_Config.STATUS = RESET;
}

int main()
{
	SPI_Handler_t SPI;
	const uint8_t send_msg[]= "Hi";
	uint8_t rec_msg[21];

	SPI_Setup(&SPI);

	if(SPI_EN_DI(&SPI.SPI_Config, ENABLE))
	{
		SPI_INI_DEINI(&SPI, INITIALIZE);
		SPI_MSG_Send_Rec(&SPI, send_msg, rec_msg, strlen(send_msg));
		SPI_INI_DEINI(&SPI, DEINITIALIZE);
	}




}
/*
SPI->SPI_Config.PIN_CLK = PIN_4;
SPI->SPI_Config.PIN_MISO = PIN_6;
SPI->SPI_Config.PIN_MOSI = PIN_5;
SPI->SPI_Config.PIN_NS = PIN_7;
SPI->SPI_Config.pPort = GPIOA;
SPI->SPI_Config.STATUS = RESET;
*/
