// -----------------------------------------------------------------------
//   Copyright (C) Rodrigo Almeida 2014
// -----------------------------------------------------------------------
//   Arquivo: keypad.c
//            Biblioteca de operação de um teclado matricial
//   Autor:   Rodrigo Maximiano Antunes de Almeida
//            rodrigomax at unifei.edu.br
//   Licença: GNU GPL 2
// -----------------------------------------------------------------------
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// -----------------------------------------------------------------------

#include "keypad.h"
#include "pic18f4520.h"

static unsigned char valor = 0x00;

unsigned char kpRead(void) {
    switch(valor){
        case (0x01):
            valor = 10;
            return valor;
            break;
        case (0x02):
            valor = 11;
            return valor;
            break;
        case (0x04):
            valor = 3;
            return valor;
            break;
        case (0x08):
            valor = 6;
            return valor;
            break;
        case (0x10):
            return 2;
            break;
        case (0x20):
            return 5;
            break;
        case (0x40):
            return 1;
            break;
        case (0x80):
            return 4;
            break;
    }
    
    return valor;
}

void kpDebounce(void) {
    unsigned char i, j;
    static unsigned char tempo;
    static unsigned char valorNovo = 0x0000;
    static unsigned char valorAntigo = 0x0000;

    for (i = 0; i < 4; i++) {
        TRISB = ~((unsigned char)1<<i);
        PORTB = ~((unsigned char)1<<i);

        //realiza o teste para cada bit e atualiza a variável
        for (j = 0; j < 2; j++) {
            if (!BitTst(PORTB, j + 4)) {
                BitSet(valorNovo, (i * 2) + j);
            } else {
                BitClr(valorNovo, (i * 2) + j);
            }
        }
    }
    if (valorAntigo == valorNovo) {
        tempo--;
    } else {
        tempo = 10;
        valorAntigo = valorNovo;
    }
    if (tempo == 0) {
        valor = valorAntigo;
    }
}

void kpInit(void) {
    TRISB = 0xF0; //quatro entradas e quatro saidas
    BitClr(INTCON2, 7); //liga pull up
    ADCON1 = 0b00001110; //apenas AN0 é analogico, a referencia é baseada na fonte

#ifdef PIC18F4550
    SPPCFG = 0x00;          // SFR nao presente no PIC18F4520
#endif
}
