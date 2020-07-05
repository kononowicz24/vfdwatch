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
#define NUMDIGITS 2
#include "vfd.h"

void setup() {
  // put your setup code here, to run once:
  DDRB = 0b00000011;
  PORTB = 0b00000011; //enable 2VOUT
  DDRD = 0b11111100;
  DDRA = 0xff;
  DDRC = 0xff;

  PORTD = 0b00010100; //L blu
  //vfd_set_disp(69);
  //PORTC = 0b10101010
}

void loop() {
  // put your main code here, to run repeatedly:
  //vfd_display();
  PORTC=0XFF;
  delay(300);
  PORTC=0X00;
  delay(300);
}