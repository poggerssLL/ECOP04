#include "pic18f4520.h"
#include "config.h"
#include "ssd.h"
#include "timer.h"
#include "keypad.h"
#include "adc.h"
char flag;
unsigned int ADvalor;
unsigned char tecla;

void Int(void) __interrupt() {
    if (BitTst(INTCON, 2)) { //Verifica se ocorreu overflow de TMR0
        timerReset(5000); //Ajusta o contador do TMR0 para 1ms
        BitClr(INTCON, 2); //Desliga o Flag de everflow do TMR0
        flag = 1;
    }
    if (BitTst(PIR1, 6)) { //Rotina para interrupção (fim de conversão AD)
        ADvalor = ADRESH;
        ADvalor <<= 8;
        ADvalor += ADRESL;
        BitClr(PIR1, 6); //limpa a flag
    }
}

void main(void) {
    float cont = 0;
    ssdInit();
    adcInit();
    timerInit();
    kpInit();
    BitClr(RCON, 7); //desabilita IPEN
    BitSet(INTCON, 7); //habilita GIE (Global Interrupt)
    BitSet(INTCON, 6); //habilita interrupção de periféricos
    BitSet(INTCON, 5); //int. timer0 (TMR0 Overflow)
    PORTD = 0;
    for (;;) {
        cont++;
        ADCON0 |= 0x02;
        ssdUpdate();
        kpDebounce();
        ADvalor = ADvalor/2;
        ssdDigit((ADvalor) % 10, 1);
        ssdDigit((ADvalor / 10) % 10, 2);
        ssdDigit((ADvalor / 100) % 10, 3);
        if (kpRead() != tecla) {
            tecla = kpRead();
            for (int i = 0; i < 8; i++) {
                if (BitTst(tecla, i)) {
                    ssdDigit(i, 0);

                }
            }


        }

        while (!flag);
        flag = 0;
    }
}
