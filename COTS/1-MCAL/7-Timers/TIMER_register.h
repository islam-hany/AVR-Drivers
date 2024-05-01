/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TIMER			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0	*((volatile u8*)0x53)
#define TCCR0_WGM00		6				//Wave Form generation modes
#define TCCR0_WGM01		3				//Wave Form generation modes
#define TCCR0_COM01		5				//compare match output mode
#define TCCR0_COM00		4				//compare match output mode
#define TCCR0_CS02		2				//Clock Select by defining th prescaler
#define TCCR0_CS01		1				//Clock Select by defining th prescaler
#define TCCR0_CS00		0				//Clock Select by defining th prescaler

#define	TCNT0	*((volatile u8*)0x52)		// for Setting the preload value in normal mode

#define	OCR0	*((volatile u8*)0x5C)		// for Setting the compare match value

#define TIMSK	*((volatile u8*)0x59)
#define TIMSK_OCIE0		1				//Output Compare Match Interrupt Enable
#define TIMSK_TOIE0		0				//Overflow Interrupt Enable
#define TIMSK_TICIE1	5				//Input Capture Interrupt Enable
#define TIMSK_OCIE1A	4				// Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B	3				// Output Compare B Match Flag
#define TIMSK_TOIE1		2				//Overflow Flag

#define TIFR	*((volatile u8*)0x58)
#define TIFR_OCF0	1					//Output Compare Match Flag
#define TIFR_TOV0	0					//Timer Overflow Flag
#define TIFR_ICF1	5					//Input Capture Flag
#define TIFR_OCF1A	4					//Output Compare A Match Flag
#define TIFR_OCF1B	3					//Output Compare B Match Flag
#define TIFR_TOV1	2					//Overflow Flag

#define	TCCR1A		*((volatile u8*)0x4f)
#define	TCCR1A_COM1A1	7				//Compare Output Mode
#define	TCCR1A_COM1A0	6				//Compare Output Mode
#define	TCCR1A_COM1B1	5				//Compare Output Mode
#define	TCCR1A_COM1B0	4				//Compare Output Mode
#define	TCCR1A_WGM11	1				//Waveform Generation Mode
#define	TCCR1A_WGM10	0				//Waveform Generation Mode

#define	TCCR1B		*((volatile u8*)0x4E)
#define	TCCR1B_ICNC1	7				//Input Capture Noise Canceler 
#define	TCCR1B_ICES1	6				//Input Capture Edge Select
#define	TCCR1B_CS12		2				//Clock Select
#define	TCCR1B_CS11		1				//Clock Select
#define	TCCR1B_CS10		0				//Clock Select
#define	TCCR1B_WGM13	4				//Waveform Generation Mode
#define	TCCR1B_WGM12	3				//Waveform Generation Mode

#define TCNT1		*((volatile u16*)0x4C)			// Timer/Counter1 register 
#define TCNT1H		*((volatile u8*)0x4D)			// Timer/Counter1 register higher byte
#define TCNT1L		*((volatile u8*)0x4C)			// Timer/Counter1 register lower byte

#define OCR1A		*((volatile u16*)0x4A)			// Output Compare Register 1 A
#define OCR1AL		*((volatile u8*)0x4A)
#define OCR1AH		*((volatile u8*)0x4B)

#define OCR1B		*((volatile u16*)0x48)			// Output Compare Register 1 B
#define OCR1BL		*((volatile u8*)0x48)	
#define OCR1BH		*((volatile u8*)0x49)

#define ICR1		*((volatile u16*)0x46)			//Input Capture Register 1 can hold Top value for Fast PWM mode 
#define ICR1L		*((volatile u8*)0x46)
#define ICR1H		*((volatile u8*)0x47)
	
#endif