/*
 * Portable Mikrocontroller-Plattform, mit einer vollen Tastatur und Funktionstasten,
 * einem 384x160x2 Graustufen-LCD, EEPROM und einem Funk-fähigen Atmel AVR.
 * SMART_ResponseXE.c
 *
 * Created: 10.09.2018 10:43:35
 * Author : RMT
 */ 

#include "sxe_driver.h"

#define SendAndDeleteBuffer(x) do{ST7586_sendReservedArea(&x);glcd_useNormalMethod();ST7586_destroyReservedArea(&x);}while(0)

int main(void)
{
	sxe_initHW();
	
	uint8_t pressedKey;
	uint8_t releasedKey;
	char textBuf[64];
	
	// Text Demo, uses the Driver-Buffering feature
	
	glcd_draw_line(30,83,80,0,ST7586_COLOR_BLACK);
	glcd_draw_line(304,0,354,83,ST7586_COLOR_BLACK);
	glcd_setTextSize(3);
	glcd_buf_print_P(84,0,"WC-Steuerung");
	glcd_buf_print_P(75,27,"Diagnoseger\x84t");
	glcd_setTextSize(2);
	glcd_buf_print_P(48,60,"Matterhorn Gotthard Bahn");
	glcd_setTextSize(1);
	
	// I know it looks ugly, but it's a demo, so... (shrug)
	glcd_buf_print_P(0,82,"Character Table:");
	for (uint8_t i = 1; i < 64; i++)
	{
		textBuf[i-1] = i;
	}
	textBuf[63] = 0;
	glcd_buf_print(0,91,textBuf);
	for (uint8_t i = 64; i < 127; i++)
	{
		textBuf[i-64] = i;
	}
	textBuf[63] = 0;
	glcd_buf_print(0,100,textBuf);
	for (uint8_t i = 127; i < 190; i++)
	{
		textBuf[i-127] = i;
	}
	textBuf[63] = 0;
	glcd_buf_print(0,109,textBuf);
	for (uint8_t i = 190; i < 253; i++)
	{
		textBuf[i-190] = i;
	}
	textBuf[63] = 0;
	glcd_buf_print(0,118,textBuf);
	
	textBuf[0] = 253;
	textBuf[1] = 254;
	textBuf[2] = 0;
	glcd_buf_print(0,127,textBuf);
		
    while (1) 
    {
		pressedKey = sxe_getPressedKey();
		releasedKey = sxe_getReleasedKey();
		
		itoa(pressedKey, textBuf, 16);
		glcd_buf_print(0, 0, textBuf);
		itoa(releasedKey, textBuf, 16);
		glcd_buf_print(0, 9, textBuf);
		
		textBuf[0] = pressedKey;
		textBuf[1] = 0;
		glcd_buf_print(15, 0, textBuf);
		textBuf[0] = releasedKey;
		glcd_buf_print(15, 9, textBuf);
		
		_delay_ms(1000);
		glcd_buf_print(0, 0, "    ");
		glcd_buf_print(0, 9, "    ");
    }
}