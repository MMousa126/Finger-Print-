/*
 * MemMap.h
 *
 *  Created on: Oct 17, 2023
 *      Author: M.Moussa
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

/******************************** DIO ****************************************/

/* identify Registers of Group A */

#define		PORTA		*((volatile u8*)0x3B) // unsigned char -> because of shifting
#define		DDRA		*((volatile u8*)0x3A)
#define		PINA		*((volatile u8*)0x39)

/* identify Registers of Group B */

#define		PORTB		*((volatile u8*)0x38)
#define		DDRB		*((volatile u8*)0x37)
#define		PINB		*((volatile u8*)0x36)

/* identify Registers of Group C */

#define		PORTC		*((volatile u8*)0x35)
#define		DDRC		*((volatile u8*)0x34)
#define		PINC		*((volatile u8*)0x33)

/* identify Registers of Group D */

#define		PORTD		*((volatile u8*)0x32)
#define		DDRD		*((volatile u8*)0x31)
#define		PIND		*((volatile u8*)0x30)

/******************************** ADC ****************************************/

#define		ADMUX			*((volatile u8*)0x27)
#define		ADMUX_ADLAR		5
#define		ADMUX_REFS0		6
#define		ADMUX_REFS1		7

#define		ADCSRA			*((volatile u8*)0x26)
#define		ADCSRA_ADPS0	0
#define		ADCSRA_ADPS1	1
#define		ADCSRA_ADPS2	2
#define		ADCSRA_ADIE		3
#define		ADCSRA_ADIF		4
#define		ADCSRA_ADATE	5
#define		ADCSRA_ADSC		6
#define		ADCSRA_ADEN		7


#define		ADCH			*((volatile u8*)0x25)
#define		ADCL			*((volatile u8*)0x24)
#define		ADC_DATA		*((volatile u16*)0x24)

/****************************************************************************************************/

/************************************ EXTI *********************************************************/

#define		GICR			*((volatile u8*)0x5B)
#define		GICR_INT1		7
#define		GICR_INT0		6
#define		GICR_INT2		5

/*********************************************************************************/

#define		GIFR			*((volatile u8*)0x5A)
#define		MCUCR			*((volatile u8*)0x55)
#define		MCUCR_ISC11		3
#define		MCUCR_ISC10		2
#define		MCUCR_ISC01		1
#define		MCUCR_ISC00		0

/*********************************************************************************/

#define		MCUCSR			*((volatile u8*)0x54)
#define		MCUCSR_ISC2		6



/************************************ EEPROM( NVM ) *********************************************************/

#define		EEARL			*((volatile u16*)0x3E)
#define		EEDR			*((volatile u8*)0x3D)


#define		EECR			*((volatile u8*)0x3C)
#define		EECR_EERIE		3
#define		EECR_EEMWE		2
#define		EECR_EEWE		1
#define		EECR_EERE		0

/*************************** TIMER0 ***************************************/
#define		TCCR0				*((volatile u8*)0x53)			/* Timer0 control register */
#define		TCNT0  				*((volatile u8*)0x52)


/****** for modes  ********/
#define		TCCR0_WGM00			6								/* Wavefoem generation Mode bit0 */
#define		TCCR0_WGM01			3								/* Wavefoem generation Mode bit1 */

/****** for HW PWM Clear on Compare Match & Set on Top *******/
#define		TCCR0_COM01			5								/* Wavefoem generation Mode 3 */
#define		TCCR0_COM00			4								/* Wavefoem generation Mode 3 */
/**************************************/
#define		TCCR0_CS02			2								/* Prescaler Selection bit2 */
#define		TCCR0_CS01			1								/* Prescaler Selection bit1 */
#define		TCCR0_CS00			0								/* Prescaler Selection bit0 */

#define 	OCR0				*((volatile u8*)0x5c)			/* output compare register 0 */

#define 	TIMSK				*((volatile u8*)0x59)			/* Timer mask */
#define 	TIMSK_TICIE1		5								/* Timer1 input capture interrupt enable */
#define 	TIMSK_OCIE0			1								/* output compare 0 interrupt enable */
#define 	TIMSK_TOIE0			0
#define 	TIMSK_TOIE1			2
#define		TIMSK_OCIE1A		4
#define		TIMSK_OCIE1B		3


/*************************** TIMER1 ***************************************/

#define		TCCR1A				*((volatile u8*)0x4f)				/* Timer1A control register */
#define		TCCR1A_COM1A1		7									/* output compare mode for unit A*/
#define		TCCR1A_COM1A0		6									/* output compare mode for unit A*/
#define		TCCR1A_WGM11		1									/* for mode choosing for unit A */
#define		TCCR1A_WGM10		0									/* for mode choosing for unit A */
#define 	TCCR1A_COM1B0		4
#define 	TCCR1A_COM1B1		5

#define 	TCNT1				*((volatile u16*)0x4c)



#define		TCCR1B				*((volatile u8*)0x4e)				/* Timer1B control register */
#define		TCCR1B_ICES1		6									/* input capture edge selection */
#define		TCCR1B_WGM13		4									/* for mode choosing for unit B */
#define		TCCR1B_WGM12		3									/* for mode choosing for unit B */
#define		TCCR1B_CS12			2									/* Prescaler Selection bit2 */
#define		TCCR1B_CS11			1	                                /* Prescaler Selection bit1 */
#define		TCCR1B_CS10			0                                   /* Prescaler Selection bit0 */

#define 	TCNT1L				*((volatile u16*)0x4c)				/* timer / counter 1 register indecate for 16 bit to location one after on in memory */

#define 	ICR1				*((volatile u16*)0x46)				/* Timer1 input compare register A low bits u16 to point to ICR1L & ICR1H */
#define 	OCR1A				*((volatile u16*)0x4a)
#define 	OCR1B				*((volatile u16*)0x48)				/* Timer1 output compare register A low bits u16 to point to OCR1L & OCR1H */

/*************************** UART ***************************************/

// UART Data Register
#define UDR     *((volatile unsigned char*)0x2C)

// UART Control and Status Registers A, B, and C
#define UCSRA   *((volatile unsigned char*)0x2B)
#define UCSRB   *((volatile unsigned char*)0x2A)
#define UCSRC   *((volatile unsigned char*)0x40)

// UART Baud Rate Registers High and Low
#define UBRRH   *((volatile unsigned char*)0x40)
#define UBRRL   *((volatile unsigned char*)0x29)


// UART Control and Status Register A (UCSRA) Bits
#define UCSRA_MPCM    0 // Multi-Processor Communication Mode
#define UCSRA_U2X     1 // Double the USART Transmission Speed
#define UCSRA_PE      2 // Parity Error
#define UCSRA_DOR     3 // Data OverRun
#define UCSRA_FE      4 // Frame Error
#define UCSRA_UDRE    5 // USART Data Register Empty
#define UCSRA_TXC     6 // USART Transmit Complete
#define UCSRA_RXC     7 // USART Receive Complete

// UART Control and Status Register B (UCSRB) Bits
#define UCSRB_TXB8    0 // Transmit Data Bit 8
#define UCSRB_RXB8    1 // Receive Data Bit 8
#define UCSRB_UCSZ2   2 // Character Size (Bit 2)
#define UCSRB_TXEN    3 // Transmitter Enable
#define UCSRB_RXEN    4 // Receiver Enable
#define UCSRB_UDRIE   5 // USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE   6 // USART Transmit Complete Interrupt Enable
#define UCSRB_RXCIE   7 // USART Receive Complete Interrupt Enabl

// UART Control and Status Register C (UCSRC) Bits
#define UCSRC_UCPOL   0 // Clock Polarity
#define UCSRC_UCSZ0   1 // Character Size (Bit 0)
#define UCSRC_UCSZ1   2 // Character Size (Bit 1)
#define UCSRC_USBS    3 // Stop Bit Select
#define UCSRC_UPM0    4 // Parity Mode Bit 0
#define UCSRC_UPM1    5 // Parity Mode Bit 1
#define UCSRC_UMSEL   6 // USART Mode Select
#define UCSRC_URSEL   7 // Register Select Bit




/******************************************************************************/
/* SPI */
/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0

/****************************** EEPROM Control Register ****************************/
/* EEPROM Control Register */
#define EECR	(*(volatile unsigned char*)0x3C)

#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0

/* EEPROM Data Register */
#define EEDR	(*(volatile unsigned char*)0x3D)

/* EEPROM Address Register */
#define EEAR	(*(volatile unsigned short*)0x3E)
#define EEARL	(*(volatile unsigned char*)0x3E)
#define EEARH	(*(volatile unsigned char*)0x3F)

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWBR    (*(volatile unsigned char*)0x20)
#define TWSR    (*(volatile unsigned char*)0x21)
#define TWAR    (*(volatile unsigned char*)0x22)
#define TWDR    (*(volatile unsigned char*)0x23)

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* SPMCR */
#define SPMIE   7
#define RWWSB   6
/* bit 5 reserved */
#define RWWSRE  4
#define BLBSET  3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0
/*********************************************************************************/

#define			 WDTCR			*((volatile u8*)0x41)
#define			 WDTOE	        4
#define			 WDE 		    3
#define			 WDP2		    2
#define			 WDP1		    1
#define			 WDP0		    0

/************************************ ISR Vectors ***************************************************/



/* INTERRUPT FUNCTIONS */

/* that's like i am talking to compiler to let this because it's assembly not c*/

/* Global Interrupt Enable but this is an assembly instruction */
#define		sei()			__asm__ __volatile__ ("sei" ::)
/* Global Interrupt Disable but this is an assembly instruction */
#define		cli()			__asm__ __volatile__ ("cli" ::)
#define		reti()			__asm__ __volatile__ ("reti" ::)

// this method to write an assembly in c -> __asm__ __volatile__ ("ret" ::)
#define		ret()			__asm__ __volatile__ ("ret" ::)

#define 	ISR(vector)		void vector(void)__attribute__((signal));\
							void vector(void)



/*#define 	ISR(vector,...)		void vector(void)__attribute__((signal))__VA_ARGS__;\
								void vector(void)
 */

/* INTERRUPT VECTORS */

/* External Interrupt Request 0 */
#define 	INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define 	INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define 	INT2_vect			__vector_3
/* TIMER/COUNTER2 Compare Match */
#define 	TIMER2_COMP_vect 	__vector_4
/* TIMER/COUNTER2 Overflow */
#define 	TIMER2_OVF_vect		__vector_5
/* TIMER/COUNTER1 Capture Unite Event */
#define 	TIMER1_ICU_vect		__vector_6
/* TIMER/COUNTER1 Compare Match A */
#define 	TIMER1_OCA_vect		__vector_7
/* TIMER/COUNTER1 Compare Match B */
#define 	TIMER1_OCB_vect		__vector_8
/* TIMER/COUNTER1 Overflow */
#define 	TIMER1_OVF_vect		__vector_9
/* TIMER/COUNTER0 Compare Match */
#define 	TIMER0_OC_vect		__vector_10
/* TIMER/COUNTER0 Overflow */
#define 	TIMER0_OVF_vect		__vector_11
/* Serial Transfer Complete */
#define 	SPI_STC_vect		__vector_12
/* USART , RX Complete */
#define 	UART_RX_vect		__vector_13
/* USART Data Register Empty */
#define 	UART_UDRE_vect		__vector_14
/* USART , TX Complete */
#define 	UART_TX_vect		__vector_15
/* ADC Conversion Complete */
#define 	ADC_vect			__vector_16
/* EEPROM Ready */
#define 	EE_RDY_vect			__vector_17
/* Analog Comparator */
#define 	ANA_COMP_vect		__vector_18
/* 2-wire Serial Interface */
#define 	TWI_vect			__vector_19
/* Store Program Memory Ready */
#define 	SPM_RDY_vect		__vector_20

#define 	BAD_vect			__vector_default

// to open global interrupt before saving context (Pushing )
#define 	ISR_NOBLOCK			__attribute__((interrupt))


// doesn't make push & pop in ISR
#define 	ISR_NACKED			__attribute__((nacked))

// __VA_ARGS__ will be removed and replaced by -> __attribute__((interrupt))


#define 	GLOBAL_ENABLE		sei


#endif /* MEMMAP_H_ */

