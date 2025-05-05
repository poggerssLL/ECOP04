#include "pic18f4520.h"
#include "config.h"
#include "ssd.h"
void main(void) {
float tempo;
int cont=0;
int impar = 0;
int min = 0;
ssdInit();
for (;;) {
    impar ++;
    if(impar %3 == 0){
    cont++;
    if(cont > 6000){
        min ++;
        cont = 0;
    }
    }
ssdDigit(((cont/100) %10), 0);//1s
ssdDigit(((cont/1000)%10), 1);//10s
ssdDigit(((min)%10), 2);//1m
ssdDigit(((min/10)%10), 3);//1m
ssdUpdate();
for (tempo = 0;tempo < 12;tempo++); // +- 10ms
}
}
