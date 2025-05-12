#include "config.h"
#include "pic18f4520.h"
#include "lcd.h"
#include "keypad.h"
/*void lcdPosition(unsigned char linha, unsigned char coluna){
    unsigned char data = 0x80;
    if (linha == 0){    
        data = 0x80 + coluna;
    }
    if (linha == 1){
        data = 0xC0 + coluna;
    }
    lcdCommand(data);
}

void main(void) {
 unsigned int tecla = 16;
 unsigned char coluna=0,linha=0;
 lcdInit();
 kpInit();
 lcdCommand(0x80);
 for(;;){
kpDebounce();
if (kpRead() != tecla){
tecla = kpRead();
if (BitTst(tecla,0)) linha=0; //tecla A
if (BitTst(tecla,3)) linha=1; //tecla 6
if (BitTst(tecla,1)) coluna++; //tecla B
if (BitTst(tecla,5)) coluna--; //tecla 5
lcdPosition(linha,coluna);
}
 }
}
*/
void lcdPosition(unsigned char linha, unsigned char coluna){
    unsigned char data = 0x80;
    if (linha == 0){    
        data = 0x80 + coluna;
    }
    if (linha == 1){
        data = 0xC0 + coluna;
    }
    lcdCommand(data);
}

void main(void) {
 unsigned int tecla = 16;
 unsigned char coluna=0,linha=0;
 lcdInit();
 kpInit();
 lcdCommand(0x80);
 unsigned long int cont=0;
 lcdInit();
 for(;;){
cont++;
lcdPosition(0,0);
lcdData((((cont/360000)%24)/10) + 48);
lcdData((((cont/360000)%24)%10) + 48);
lcdData(':');
lcdData((cont/60000)%6 + 48);
lcdData((cont/6000)%10 + 48);
lcdData(':');
lcdData((cont/1000)%6 + 48);
lcdData((cont/100)%10 + 48);
//ciclo de 10ms +-.
lcdPosition(linha,coluna);
kpDebounce();
if (kpRead() != tecla){
tecla = kpRead();
if (BitTst(tecla,6)) cont += 360000; //tecla A
if (BitTst(tecla,7)) cont -= 360000; //tecla 6
if (BitTst(tecla,4)) cont += 6000; //tecla B
if (BitTst(tecla,5)) cont -= 6000;
if (BitTst(tecla,0)) cont += 100;
if (BitTst(tecla,3)) cont -= 100;//tecla 5
}
}
}
 
