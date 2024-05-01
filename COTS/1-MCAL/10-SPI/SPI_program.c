/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SPI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_voidMasterInit()
{
	//Clock prescaler divide by 16
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPSR_SPI2X);
	
	//Master initialization
	SET_BIT(SPCR,SPCR_MSTR);
	
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit()
{
	
	
	//Slave initialization
	CLR_BIT(SPCR,SPCR_MSTR);
	
	//SPI enable
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	SPDR=Copy_u8Data;
	while(0==GET_BIT(SPSR,SPSR_SPIF));
	return SPDR;
}


