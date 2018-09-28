/*
 * sxe_pinout.h
 *
 * Created: 20.09.2018 07:26:18
 *  Author: RMT
 */ 


#ifndef SXE_PINOUT_H_
#define SXE_PINOUT_H_

// SPI I/O
#define SPIPORT		PORTB
#define SPIDDR		DDRB
#define SPISS		PB0
#define SPISCK		PB1	
#define SPIMOSI		PB2
#define SPIMISO		PB3

// Display-Specific I/O
#define DISPDDR_CE		DDRE
#define DISPPORT_CE		PORTE
#define DISPPIN_CE		PE7
#define DISPDDR_A0		DDRD
#define DISPPORT_A0		PORTD
#define DISPPIN_A0		PD6
#define DISPDDR_RST		DDRG
#define DISPPORT_RST	PORTG
#define DISPPIN_RST		PG2

// EEPROM-Specific I/O
#define EEPROMDDR		DDRD
#define EEPROMPORT		PORTD
#define EEPROMCS		PD3

// Keyboard-Specific I/O
#define KEYBOARDROWDDR1		DDRD
#define KEYBOARDROWPORT1	PORTD
#define KEYBOARDROW61		PD7
#define KEYBOARDROW91		PD5
#define KEYBOARDROW101		PD4
#define KEYBOARDROWDDR2		DDRE
#define KEYBOARDROWPORT2	PORTE
#define KEYBOARDROW12		PE4
#define KEYBOARDROW42		PE2
#define KEYBOARDROW52		PE1
#define KEYBOARDROWDDR3		DDRF
#define KEYBOARDROWPORT3	PORTF
#define KEYBOARDROW23		PF1
#define KEYBOARDROW33		PF3
#define KEYBOARDROWDDR4		DDRG
#define KEYBOARDROWPORT4	PORTG
#define KEYBOARDROW74		PG0
#define KEYBOARDROW84		0//PG5

#define KEYBOARDCOLDDR1		DDRB
#define KEYBOARDCOLPORT1	PORTB
#define KEYBOARDCOLPIN1		PINB
#define	KEYBOARDCOL51		PB4
#define KEYBOARDCOL41		PB5
#define KEYBOARDCOL31		PB6
#define KEYBOARDCOL21		PB7
#define KEYBOARDCOLDDR2		DDRE
#define KEYBOARDCOLPORT2	PORTE
#define KEYBOARDCOLPIN2		PINE
#define	KEYBOARDCOL62		PE0
#define KEYBOARDCOL12		PE6


#endif /* SXE_PINOUT_H_ */