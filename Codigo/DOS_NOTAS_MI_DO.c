#include <xc.h>
#pragma config FOSC = HS     // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT enabled)
// CONFIG3H
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

void main(void) {
    int a,b,s;//DECLARAMOS VARIABLES DE TIPO ENTERO
    TRISD = 0;//CONFIGURAMOS EL PUERTO DE COMO SALIDA
    TRISC = 0xff;//DECLARAMOS AL PUERTO C COMO SALIDA
    T0CON = 0XC2;//CONFIGURAMOS EL CANAL DEL TIMER
    NOSON: PORTD =0;//DECLARAMOS UNA ETIQUETA
    LEE: s=PORTC=0xff;//DECLARAMOS UNA ETIQUETA PARA QUE EL PUERTO C INICIE EN UNO 
    if(PORTCbits.RC0==0)goto DO;//DECLARAMOS CONDICIONALES PARA LAS NOTAS
    if(PORTCbits.RC1==0)goto RE;
    if(PORTCbits.RC2==0)goto MI;
    if(PORTCbits.RC4==0)goto FA;
    if(PORTCbits.RC5==0)goto SOL;
    if(PORTCbits.RC6==0)goto LA;
    if(PORTCbits.RC7==0)goto SI;
    /*switch(s){
        case1:goto DO;
        break;
        case2:goto MI;
        break;
    }*/
    goto LEE;//UTILIZAMOS UN GOTO QUE NOS SIRVE PARA DIRIGIR A UNA LINEA ESPECIFICA DE LA ETIQUETA
    //EL RETARDO PARA LAS NOTAS
    DO: for(b=0;b<20;b++){
        PORTD = 1;
        for(a=0;a<19;a++){
            TMR0L = 244;
            SENSA1: if(INTCONbits.TMR0IF==0)goto SENSA1;
            INTCONbits.TMR0IF=0;
        } 
        PORTD = 0;
        for(a=0;a<19;a++){
            TMR0L = 244;
            SENSA2: if(INTCONbits.TMR0IF==0)goto SENSA2;
            INTCONbits.TMR0IF=0;
        }
        
    }
goto NOSON;
RE: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<17;a++){
    TMR0L = 244;
    SENSA3: if(INTCONbits.TMR0IF==0)goto SENSA3;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<17;a++){
        TMR0L=244;
        SENSA4: if(INTCONbits.TMR0IF==0)goto SENSA4;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;

MI: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<15;a++){
    TMR0L = 244;
    SENSA5: if(INTCONbits.TMR0IF==0)goto SENSA5;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<15;a++){
        TMR0L=244;
        SENSA6: if(INTCONbits.TMR0IF==0)goto SENSA6;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;
 
 FA: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<14;a++){
    TMR0L = 244;
    SENSA7: if(INTCONbits.TMR0IF==0)goto SENSA7;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<14;a++){
        TMR0L=244;
        SENSA8: if(INTCONbits.TMR0IF==0)goto SENSA8;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;
 SOL: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<13;a++){
    TMR0L = 244;
    SENSA9: if(INTCONbits.TMR0IF==0)goto SENSA9;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<13;a++){
        TMR0L=244;
        SENSA10: if(INTCONbits.TMR0IF==0)goto SENSA10;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;
 LA: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<11;a++){
    TMR0L = 244;
    SENSA11: if(INTCONbits.TMR0IF==0)goto SENSA11;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<11;a++){
        TMR0L=244;
        SENSA12: if(INTCONbits.TMR0IF==0)goto SENSA12;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;
 SI: for(b=0;b<20;b++){
    PORTD=1;
    for(a=0;a<10;a++){
    TMR0L = 244;
    SENSA13: if(INTCONbits.TMR0IF==0)goto SENSA13;
    INTCONbits.TMR0IF=0;
    }
    PORTD=0;
    for(a=0;a<10;a++){
        TMR0L=244;
        SENSA14: if(INTCONbits.TMR0IF==0)goto SENSA14;
        INTCONbits.TMR0IF=0;
    }
}
 goto NOSON;
 FIN: goto FIN;
    return;
    //Y ASI PARA TODAS LAS NOTAS 
}
