/**
 * Luiz Brito da Rosa   
 * Trabalho 001 
 * Mostrar o dia e o mes do aniversario 
 * 14.01
 */ 

#include <xc.h>

#include "config.h"

#define _XTAL_FREQ 8000000

#define seg_port LATB

#define digit1 PORTAbits.RA0
#define digit2 PORTAbits.RA1
#define digit3 PORTAbits.RA2
#define digit4 PORTAbits.RA3

char num[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 
void inicializaParam(void){
    TRISA = 0b0;
    TRISB = 0b10000000;
    PORTA = 0b0;
    PORTB = 0b0;

    digit1=0;
    digit2=0; 
    digit3=0;
    digit4=0;
}

mostraAniversario(void){
    digit1=1; 
    seg_port=num[1];//0x06; //1
    __delay_ms(10); 
    digit1=0; 

    digit2=1; 
    seg_port=num[4];//0x66;//4 
    __delay_ms(10); 
    digit2=0; 

    digit3=1;   
    seg_port=num[0];//0x3F;// 0
    __delay_ms(10); 
    digit3=0; 

    digit4=1;   
    seg_port=num[9];//0x06;// 1
    __delay_ms(10); 
    digit4=0;
    __delay_ms(10);
}

void main(void) {
    inicializaParam();
    int w = 0;    
    while (1){
        w = mostraAniversario();    
    } 
}
