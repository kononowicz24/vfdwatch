#ifndef __VFD_H
#define __VFD_H

#define GRIDPORT PORTC
#define GRIDMASK 0b00111100

#define SEGPORT PORTA
#define SEGPORT2 PORTC
#define SEGPORT2MASK 0b11000000

#ifdef VFD_LD8051
//TODO: LD8051

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

#define PORT_SEG_D PORTC
#define PORT_SEG_E PORTC
#define PORT_SEG_C PORTA
#define PORT_SEG_F PORTA
#define PORT_SEG_G PORTA
#define PORT_SEG_A PORTA
#define PORT_SEG_DP PORTA
#define PORT_SEG_B PORTA


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

#define PORT_SEG_D PORTC
#define PORT_SEG_E PORTC
#define PORT_SEG_C PORTA
#define PORT_SEG_F PORTA
#define PORT_SEG_G PORTA
#define PORT_SEG_A PORTA
#define PORT_SEG_DP PORTA
#define PORT_SEG_B PORTA

#define VFDPC0 0b11000000 //e d X X X X x x
#define VFDPA0 0b11010100 //c f g a p b X X

#define VFDPC1 0b00000000
#define VFDPA1 0b10000001

#define VFDPC2 0b11000000
#define VFDPA2 

#endif
#endif

int digit1 =0;
int digit2 =0;
int digit3 =0;
int digit4 =0;

bool vfd_set_disp(int number) {
    digit1 = number/10; //todo refactor 4 digits
    digit2 = number%10;
}

void vfd_set_ports(int a) {
    switch (a) {
        case 0: 
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        default:
    }
}

void vfd_display() {
    //digit 1
    for (int i=0; i<NUMDIGITS; i++) { //grids are on PC2 to PC5, for 2 PC2 and PC3
        
    }
}

#endif