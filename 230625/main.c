//includes

#include "adc.h"
#include "config.h"
#include "keypad.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "timer.h"
#include "serial.h"
#include "pwm.h"


void LeTeclado(void);
void Serial(void);
void MostraDisplay(void);
void lcdPrint(char* str);
void lcdClear(void);
void Temperatura(int temp);

void main(void) {
    char slot;
    lcdInit();
    kpInit();
    timerInit();
    serialInit();
    pwmInit();
    pwmFrequency(1000);
    adcInit();
    ssdInit();
   
    //inicializações
    for (;;) {

        timerReset(5000);
        ssdUpdate();

        switch (slot) {
            case 0:
                LeTeclado();
                slot = 1;
                break;
            case 1:
                Serial();
                slot = 2;
                break;
            case 2:
                kpDebounce();
                slot = 3;
                break;
            case 3:
                MostraDisplay();
                slot = 0;
                break;
            default:
                slot = 0;
                break;
        }
        

        timerWait();
    }
}

void LeTeclado() {
    unsigned char tecla;
    kpDebounce();

    if (kpRead() != tecla) {
        tecla = kpRead();
        if (BitTst(tecla, 2)) { //tecla 3
            lcdCommand(0x80);
            lcdPrint("Erick ");
        }
        if (BitTst(tecla, 6)) {// tecla 1
            lcdCommand(0xC0);

            lcdPrint("2024004143 ");
        }
        if (BitTst(tecla, 5)) {//tecla 5
            lcdCommand(0x80);
            lcdClear();
            lcdCommand(0xC0);
            lcdClear();


        }
        if (BitTst(tecla, 4)) {//tecla 2

            pwmSet1(100);
        }
        if (BitTst(tecla, 3)) {//tecla 6

            pwmSet1(0);
        }



        return;
    }
}

void Serial() {
    unsigned char serialAtual;
    serialAtual = serialRead();

    if (serialAtual != 0) {
        switch (serialAtual) {
            case 'a':
                lcdCommand(0x80);
                lcdPrint("Erick Kei ");
                break;

            case 'b':
                lcdCommand(0xC0);
                lcdPrint("2024004143 ");
                break;
            case 'c':
                pwmSet1(100);
                break;
            case 'd':
                pwmSet1(0);
                break;
            case'0':
                lcdCommand(0x80);
                lcdClear();
                lcdCommand(0xC0);
                lcdClear();

                break;
        }
        int temp = adcRead() / 2;
        serialSend('T');
        serialSend(':');
        serialSend(((temp / 10) % 10) + 48);
        serialSend((temp % 10) + 48);
        serialSend(13);
    }

}

void MostraDisplay() {
    int temp = adcRead()/2;
    ssdDigit(((adcRead()/20)%10), 1);
    ssdDigit(((adcRead()/2)%10), 0);
    return;
}

void lcdPrint(char* str) {
    unsigned char i = 0;
    while (str[i] != '\0') {
        lcdData(str[i]);
        i++;
    }
}

void lcdClear(void) {
    unsigned char i = 16;
    while (i > 0) {
        lcdData(' ');
        i--;
    }
}

