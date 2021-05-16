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

#include "vfd2.h"

#define RTCREFRESHMILLIS 500
volatile long long rtcLastMillis = -1*RTCREFRESHMILLIS;

#define HRDISPMILLIS 500
#define MINDISPMILLIS 500
volatile unsigned long long hrDispLastMillis = -1*HRDISPMILLIS;

uint8_t disp_hour = 88;
uint8_t disp_minu = 88;

void refreshTime() {
    disp_hour = ds3231m_getHours();
    disp_minu = ds3231m_getMinutes();
    rtcLastMillis = millis();
}

#define NUM_STATES 3

enum state {SHOW_HOUR, SHOW_MINUTE, SHOW_COMPASS, SET_MINUTE, SET_HOUR, ALL_OFF};

state current_state = SHOW_HOUR;

ISR(PCINT1_vect) {
  cli();
  if (!(PINB & 0x20)) { //PB5
    hrDispLastMillis = millis();
  }
  sei();
}

void setup() {
  // put your setup code here, to run once:
  cli();
  DDRD = 0b11111100;
  DDRA = 0xff;
  DDRC = 0xfd;

  PORTD = 0b00010100; //L blu
  //vfd_set_disp(69);
  //PORTC = 0b10101010
  delay(300);
  DDRB = 0b00000011;
  PORTB = 0b00000011; //enable 2VOUT

  //PORTB = 0b00000000; //disable 2VOUT and 12Vout

  //buttons setup
  DDRB &= 0x1F; // SET  PB7, PB6, PB5 as inputs
  //PC7 = SW1 - upper
  //PC6 = SW2 - lower
  PCMSK1 |= 0xE0; //enable PCINT
  PCICR |= 0x02; //enable PCINT bank 2
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  //vfd_display();
  /*
  PORTB = 0b00000011;
  delay(30);
  for(int i=0;i<150;i++) {

  }
  for(int i=0;i<150;i++) {

  }
  PORTB = 0b00000000;

  delay(2000);
  */
  //state machine
  switch (current_state)
  {
  case SHOW_HOUR:
    PORTB = 0b00000011;
    PORTA=~digits_PA[disp_hour/10]-segments_PA[0];
    PORTC=~digits_PC[disp_hour/10];
    delay(3);
    PORTA=~digits_PA[disp_hour%10]-segments_PA[1]-digits_dp_PA;
    PORTC=~digits_PC[disp_hour%10];
    delay(3);
    break;
  case SHOW_MINUTE:
    PORTB = 0b00000011;
    PORTA=~digits_PA[disp_minu/10]-segments_PA[0];
    PORTC=~digits_PC[disp_minu/10];
    delay(3);
    PORTA=~digits_PA[disp_minu%10]-segments_PA[1];
    PORTC=~digits_PC[disp_minu%10];
    delay(3);
    break;
  case ALL_OFF:
    PORTB = 0b00000000;
    PORTA = 0xff;
    PORTC = 0xFF;
    break;
  default:
    break;
  }

 
  if (millis()>rtcLastMillis+RTCREFRESHMILLIS) {
    refreshTime();
  }//check always
  //scheduler
  unsigned long long scheduler_millis = millis();
  if (scheduler_millis>=hrDispLastMillis && scheduler_millis<hrDispLastMillis+HRDISPMILLIS) {
    current_state = SHOW_HOUR;
  } else if (scheduler_millis>=hrDispLastMillis+HRDISPMILLIS && scheduler_millis<hrDispLastMillis+HRDISPMILLIS+MINDISPMILLIS) {
    current_state = SHOW_MINUTE;
  } else if (scheduler_millis>=hrDispLastMillis+HRDISPMILLIS+MINDISPMILLIS) {
    current_state = ALL_OFF;
  }

  if (disp_minu>59) disp_minu=0;
  if (disp_hour>23) disp_hour=0; //check always
}