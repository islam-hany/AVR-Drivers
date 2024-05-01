/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: CLCD		****************/
/*****************		Version: 1.00		****************/
/*****************		Date: 4/26/2023		****************/
/***********************************************************/
/***********************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define MODE_4bit 1
#define MODE_8bit 2
#define CLCD_CLEAR 1

void CLCD_voidSendCommand(u8 Copy_u8Command);


void CLCD_voidSendData(u8 Copy_u8Data);


void CLCD_voidInit(void);


void CLCD_voidSendString(const char* Copy_pu8String);

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);


void CLCD_voidWriteSpecialCharacter(const u8* Copy_pu8Pattern, u8 Copy_u8PatternNum, u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidWriteNumber(u32 Copy_u32Number, u8 Copy_u8XPos,u8 Copy_u8YPos);

#endif