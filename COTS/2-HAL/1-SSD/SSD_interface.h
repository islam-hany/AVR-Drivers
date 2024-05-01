/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: SSD		****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_u8COM_ANODE  1
#define SSD_u8COM_CATHODE 0


typedef struct 
{
	u8 SSD_Type;
	u8 DIO_Port;
	u8 SSD_Value;
	u8 SSD_EnablePort;
	u8 SSD_EnablePin;
	
}SSD_s;

u8 SSD_u8SetValue(SSD_s* Copy_Properties);
u8 SSD_u8On(SSD_s* Copy_Properties);
u8 SSD_u8Off(SSD_s* Copy_Properties);



#endif