#include "config.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "keypad.h"

void main(void) {
    char i = 0;
    int cont = 95, dezena =0, unidade = 0;
    unsigned char tecla;
    ssdInit();
    kpInit();
    for (;;) {
        ssdUpdate();
        kpDebounce();
        if(kpRead() != tecla){
            tecla = kpRead();
            for (i = 0; i < 8; i++) {
            if (BitTst(tecla, i)) {
                ssdDigit(tecla, 0);
                
            }
        }
            if (tecla != 0){
                cont ++;
            }
                    
        }
        tecla = kpRead();
        
          
        dezena = ((cont / 10) %10);
        ssdDigit(dezena, 3);
        unidade = cont %10;
        ssdDigit(unidade,2);
        if (cont == 99){
            cont == 0;
        }
    }
}
