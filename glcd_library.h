/* 
 * File:   glcd_library
 * Author: Pascal G. (gfcwfzkm), David V.
 * Comments: Ausbildung Display Programmieren
 * Revision history: 24.05.18 Erstellung der Bibliothek
 */

#ifndef GLCD_LIBRARY_H
#define	GLCD_LIBRARY_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>

#include "ST7586.h"

#define GLCD_WIDTH			ST7586_DISPLAYSIZE_X
#define GLCD_HEIGHT			ST7586_DISPLAYSIZE_Y
#define GLCD_SETXY(x,y,c)	ST7586_setPixel(x,y,c)
#define GLCD_GETXY(x,y)		ST7586_getPixel(x,y)
#define GLCD_INVXY(x,y)

uint16_t cursor_x;
uint16_t cursor_y;

void glcd_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char colour);
void glcd_draw_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char colour);
void glcd_draw_rectangle_filled(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, char colour);
void glcd_circle(uint16_t cx, uint16_t cy, uint16_t radius, char colour);
void glcd_load_image(const char image[], char colour);
void glcd_clear(char colour);
void glcd_invert();

void glcd_font();
void glcd_cursor(uint16_t x, uint16_t y);
void glcd_char(uint16_t x, uint16_t y, char character, char fgcolor);
void glcd_print(uint16_t x, uint16_t y,char *character, char fgcolor);
void glcd_print_progmem(uint16_t x, uint16_t y,const char *character, char fgcolor);
#define glcd_print_P(x,y,__s,fg)	glcd_print_progmem(x,y,PSTR(__s),fg)

#endif	/* XC_HEADER_TEMPLATE_H */