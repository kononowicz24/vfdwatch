#ifndef __VFD_H
#define __VFD_H

#define GRIDMASK 0b11000011

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

#define PCMASK_SEG 0b00111111

#define VFDPC0 0b11000000 //e d X X X X x x
#define VFDPA0 0b11010100 //c f g a p b X X

#define VFDPC1 0b00000000
#define VFDPA1 0b10000100

#define VFDPC2 0b11000000
#define VFDPA2 0b00110100

#define VFDPC3 0b01000000
#define VFDPA3 0b10110100

#define VFDPC4 0b00000000
#define VFDPA4 0b11100100

#define VFDPC5 0b01000000
#define VFDPA5 0b11110000

#define VFDPC6 0b11000000
#define VFDPA6 0b11110000

#define VFDPC7 0b00000000
#define VFDPA7 0b10010100

#define VFDPC8 0b11000000
#define VFDPA8 0b11110100

#define VFDPC9 0b01000000
#define VFDPA9 0b11110100

#endif
#endif

uint8_t digits[4];

bool vfd_set_disp(uint8_t number) {
    digits[0] = number/10; //todo refactor 4 digits
    digits[1] = number%10;
    digits[2] = 0;
    digits[3] = 0;
}

void vfd_set_ports(uint8_t a) {
    switch (a) {
        case 0: PORTC = (PINC&PCMASK_SEG) + (~VFDPC0& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA0; break;
        case 1: PORTC = (PINC&PCMASK_SEG) + (~VFDPC1& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA1; break; //TODO HARDCODE NEGATIONS
        case 2: PORTC = (PINC&PCMASK_SEG) + (~VFDPC2& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA2; break;
        case 3: PORTC = (PINC&PCMASK_SEG) + (~VFDPC3& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA3; break;
        case 4: PORTC = (PINC&PCMASK_SEG) + (~VFDPC4& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA4; break;
        case 5: PORTC = (PINC&PCMASK_SEG) + (~VFDPC5& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA5; break;
        case 6: PORTC = (PINC&PCMASK_SEG) + (~VFDPC6& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA6; break;
        case 7: PORTC = (PINC&PCMASK_SEG) + (~VFDPC7& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA7; break;
        case 8: PORTC = (PINC&PCMASK_SEG) + (~VFDPC8& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA8; break;
        case 9: PORTC = (PINC&PCMASK_SEG) + (~VFDPC9& ~PCMASK_SEG); PORTA = (uint8_t) ~VFDPA9; break;
    }
}

void vfd_display() {
    //digit 1
    //for (uint8_t i=0; i<NUMDIGITS; i++) { //grids are on PC2 to PC5, for 2 PC2 and PC3
        
        vfd_set_ports(digits[0]);
        PORTC = 0b00111100;
        _delay_us(100000);
        PORTC = 0b00000000;
        _delay_us(100000);
        //vfd_set_ports(digits[1]);
        //PORTC = (PINC&GRIDMASK) + 0b010100;
        //_delay_us(3);
    //}
}

#endif