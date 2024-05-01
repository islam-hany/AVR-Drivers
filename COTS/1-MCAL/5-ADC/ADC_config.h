/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: ADC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#ifndef ADC_CONFIGE_H_
#define ADC_CONFIGE_H_

/*
ADC Resolution options:
-RES_8bit
-RES_10bit
*/

#define ADC_RESOlUTION	RES_10bit

/*
ADC Prescaler options:
1- DIV_BY_2
2- DIV_BY_4	
3- DIV_BY_8
4- DIV_BY_16
5- DIV_BY_32
6- DIV_BY_64
7- DIV_BY_128
*/


#define	ADC_PRESCALER	DIV_BY_128

#define ADC_u32TIMEOUT	500000


#endif