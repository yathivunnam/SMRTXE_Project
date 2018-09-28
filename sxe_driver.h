/*
 * sxe_driver.h
 *
 * Created: 20.09.2018 07:33:16
 *  Author: RMT
 */ 


#ifndef SXE_DRIVER_H_
#define SXE_DRIVER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "sxe_pinout.h"
#include "hwSPI.h"
#include "ST7586.h"

#define KEY_DELETE	0x7F
#define KEY_UP		0x10
#define KEY_DOWN	0x11
#define KEY_LEFT	0x12
#define KEY_RIGHT	0x13
#define KEY_DIV		0x14
#define KEY_SQRT	0x15
#define KEY_EXP		0x16
#define KEY_SPACE	' '
#define KEY_APOSTROPH	0x27
#define KEY_PI		0x17
#define KEY_THETA	0x18
#define KEY_EQSMALLER	0x19
#define KEY_EQBIGGER	0x1A

struct keyboardHandler{
	uint8_t keys[10];		// [10] Rows, each row containing 6 columns
	uint8_t keysPressed[10];
	uint8_t keysRelease[10];
	uint8_t shift:1;
	uint8_t sym:1;
};

void sxe_initHW();

// Untested functions from here:
void sxe_scanKeyboard();

struct keyboardHandler getKeyboardHandler();

uint8_t sxe_getPressedKey();

uint8_t sxe_getReleasedKey();

uint8_t sxe_isKeyPressed(uint8_t key, uint8_t row, uint8_t col);


#endif /* SXE_DRIVER_H_ */