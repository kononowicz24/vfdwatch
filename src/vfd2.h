#ifndef __VFD2_H__
#define __VFD2_H__


int digits_PA[] = {
  0b11010100,
  0b10000100, //pa3 =0, dp controlled independently
  0b00110100, //pa1 = pa0 = 0, digits controlled independently
  0b10110100,
  0b11100100,
  0b11110000,
  0b11110000,
  0b10010100,
  0b11110100,
  0b11110100
};

int digits_PC[] = {
  0b11000000,
  0b00000000,
  0b11000000,
  0b01000000,
  0b00000000,
  0b01000000,
  0b11000000,
  0b00000000,
  0b11000000,
  0b01000000,
  0b11000000
};

int segments_PA[] = {
  0b01,
  0b10 //bedzie odejmowanko bo logic low
};

int digits_dp_PA = 0b00001000;

#endif