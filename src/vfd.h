#ifndef __VFD_H
#define __VFD_H

#define GRIDPORT PORTC
#define GRIDMASK 0b00111100

#define SEGPORT PORTA
#define SEGPORT2 PORTC
#define SEGPORT2MASK 0b11000000

#ifdef VFD_LD8051

#else
#ifdef VFD_IV3A

#define G1 2 //PC2
#define G2 3 //pc3

#define SEG_D 6 //PC6
#define SEG_E 7 //PC7
#define SEG_C 7 //PA7
#define SEG_F 6 //PA6
#define SEG_G 5
#define SEG_A 4
#define SEG_DP 3
#define SEG_B 2

#endif
#endif


#endif