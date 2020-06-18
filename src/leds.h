#ifndef __LEDS_H
#define __LEDS_H

#define LED_MASK 0b00011100
#define COLOR_MASK 0b11100000

#define LED_GRN 0b110
#define LED_BLU 0b011
#define LED_RED 0b101

#define LED_LT 0b101
#define LED_RT 0b011
#define LED_CH 0b110

#define SH_COLOR 5
#define SH_LEDSEL 2

#define LEDPORT PORTD
#define LEDDDR DDRD
#define LEDDDRSEL 0b11111100

#endif