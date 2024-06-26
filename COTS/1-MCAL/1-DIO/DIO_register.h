/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: DIO			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

 
#define  PORTA    *((volatile u8*)0x3B)
  #define  PINA     *((const volatile u8*)0x39)
  
  

  #define  PINB     *((const volatile u8*)0x36)
  #define  PORTB    *((volatile u8*)0x38)


  #define  PINC     *((const volatile u8*)0x33)
  #define  PORTC    *((volatile u8*)0x35)
  

  #define  PIND     *((const volatile u8*)0x30)
#define  PORTD    *((volatile u8*)0x32)
#endif