/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: KEYPAD	****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

u8 KPAD_u8GetPressedKey()
{
	u8 Local_u8PinState,Local_u8ColoumnIdx,Local_u8RowIdx,Local_u8PressedKey=NO_PRESSED_KEY;
	static u8 Local_u8KPADArray[4][4]={{KPAD_R0C0,KPAD_R0C1,KPAD_R0C2,KPAD_R0C3},
								{KPAD_R1C0,KPAD_R1C1,KPAD_R1C2,KPAD_R1C3},
								{KPAD_R2C0,KPAD_R2C1,KPAD_R2C2,KPAD_R2C3},
								{KPAD_R3C0,KPAD_R3C1,KPAD_R3C2,KPAD_R3C3}};
							
	static u8 Local_u8ColumnArray[NUM_OF_COLOUMNS]={KPAD_COLOUMN0_PIN,KPAD_COLOUMN1_PIN,KPAD_COLOUMN2_PIN,KPAD_COLOUMN3_PIN};
	static u8 Local_u8RowArray[NUM_OF_ROWS]={KPAD_ROW0_PIN,KPAD_ROW1_PIN,KPAD_ROW2_PIN,KPAD_ROW3_PIN};
		
	for(Local_u8ColoumnIdx=0 ; Local_u8ColoumnIdx < NUM_OF_COLOUMNS ;Local_u8ColoumnIdx++)
	{
		DIO_u8SetPinValue(KPAD_PORT,Local_u8ColumnArray[Local_u8ColoumnIdx],DIO_u8PIN_LOW);
		for(Local_u8RowIdx=0;Local_u8RowIdx < NUM_OF_ROWS ; Local_u8RowIdx++)
		{
			DIO_u8GetPinValue(KPAD_PORT,Local_u8RowArray[Local_u8RowIdx],&Local_u8PinState);
			if (DIO_u8PIN_LOW==Local_u8PinState)
			{
				while (DIO_u8PIN_LOW==Local_u8PinState)
				{
					DIO_u8GetPinValue(KPAD_PORT,Local_u8RowArray[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8KPADArray[Local_u8RowIdx][Local_u8ColoumnIdx];
			}
		}
		DIO_u8SetPinValue(KPAD_PORT,Local_u8ColumnArray[Local_u8ColoumnIdx],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
