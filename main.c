/*
 * Portable Mikrocontroller-Plattform, mit einer vollen Tastatur und Funktionstasten,
 * einem 384x160x2 Graustufen-LCD, EEPROM und einem Funk-fähigen Atmel AVR.
 * SMART_ResponseXE.c
 *
 * Created: 10.09.2018 10:43:35
 * Author : RMT
 */ 

#include "sxe_driver.h"
#include "glcd_library.h"

struct ST7586_reservedArea testArea;

void draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char colour)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = dx+dy, e2; /* error value e_xy */
	
	while(1){
		ST7586_setPixelReservedArea(&testArea, x0, y0, ST7586_COLOR_BLACK);
		if (x0==x1 && y0==y1) break;
		e2 = 2*err;
		if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

int main(void)
{
	sxe_initHW();
	ST7586_init(0);
	
	// Precise Pixel-write with the display's basic function
	for (uint8_t pos = 0; pos < ST7586_DISPLAYSIZE_Y; pos++)
	{
		ST7586_setPixel(pos, pos, ST7586_COLOR_DARKGRAY);
		ST7586_setPixel(pos+1, pos, ST7586_COLOR_LIGHTGRAY);
		ST7586_setPixel(pos+2, pos, ST7586_COLOR_DARKGRAY);
		ST7586_setPixel(pos+5, pos, ST7586_COLOR_BLACK);
	}
	
	// Text Demo, uses the Driver-Buffering feature
	glcd_print_P(50,10,"Graphics-Library for the SMART Response XE", ST7586_COLOR_BLACK);
	glcd_print_P(50,20,"Supports Pixel-Precise Control", ST7586_COLOR_BLACK);
	glcd_print_P(50,30,"In all 4 colours", ST7586_COLOR_BLACK);
	
	// Buffered Pixel example write
	testArea = ST7586_getReservedAreaMalloc(150,50,200,55);
	draw_line(150,50,200,55,ST7586_COLOR_BLACK);
	ST7586_sendReservedArea(&testArea);
	ST7586_destroyReservedArea(&testArea);
	//glcd_draw_line(150, 55, 200, 60, ST7586_COLOR_BLACK);
	ST7586_forcePixelUpdate();
	
    while (1) 
    {
		
    }
}