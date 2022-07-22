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

unsigned int m, c, d, u, i;

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

inicializaSegmento(void){
    i = 0;
    while (i < 1001) {
       
        mostraUnidade(i);
        mostraDezena(d);
        mostraCentena(c);        
        mostraMilhar(m);  
        __delay_ms(100);        
    }
}

mostraUnidade(int v){      
     u = (v%10);
     PORTAbits.RA0 = 1; 
     seg_port=num[u];
     __delay_ms(1);
     PORTAbits.RA0 = 0;
     PORTB = 0;
     __delay_ms(1);
}

mostraDezena(int v){
    d = (v%100);
    d = (d/10)-((d%10)/10);
    PORTAbits.RA1 = 1; 
    seg_port=num[d];
    __delay_ms(1);
    PORTAbits.RA1 = 0;
    PORTB = 0;
    __delay_ms(1);
}

mostraCentena(int v){ 
    c = (v%1000);
    c = (c/100)-((c%100)/100);
    PORTAbits.RA2 = 1; 
    seg_port=num[c];
    __delay_ms(1);
    PORTAbits.RA2 = 0;
    PORTB = 0;
    __delay_ms(1);
}

mostraMilhar(int v){ 
    m = (v/1000)-((v%1000)/1000);
    PORTAbits.RA3 = 1; 
    seg_port=num[v];
    __delay_ms(1);
    PORTAbits.RA3 = 0;
    PORTB = 0;
    __delay_ms(1);
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
    // seguir testar. 
    // inicializaSegmento();
}