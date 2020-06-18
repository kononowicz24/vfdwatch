#include <Arduino.h>

#define SDA_PORT PORTC
#define SDA_PIN 1
#define SCL_PORT PORTC
#define SCL_PIN 0

#define I2C_TIMEOUT 100
#define I2C_FASTMODE 1

#include <SoftWire.h>

SoftWire Wire = SoftWire();

#include "leds.h"
#include "ds3231m.h"
#define VFD_IV3A
#include "vfd.h"

void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00000011;
  PORTB = 0b00000011; //enable 2VOUT
  DDRD = 0b11111100;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = 0b01110100; //L blu
  delay(62);
  PORTD = 0b10110100; //L red
  delay(62);
  PORTD = 0b11010100; //L red
  delay(62);

  PORTD = 0b01101100; //L blu
  delay(62);
  PORTD = 0b10101100; //L red
  delay(62);
  PORTD = 0b11001100; //L red
  delay(62);

  PORTD = 0b10011000; //L blu
  delay(62);
  PORTD = 0b01011000; //L red
  delay(62);
  PORTD = 0b00111000; //L red
  delay(62);
}