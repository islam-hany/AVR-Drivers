/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: PORT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_register.h"
#include "PORT_private.h"
#include "PORT_interface.h"




void PORT_voidInit()
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	PORTA=PORTA_VAL;
	PORTB=PORTB_VAL;
	PORTC=PORTC_VAL;
	PORTD=PORTD_VAL;
}