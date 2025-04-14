
#include "led.h"

#define PORTD (*(volatile __near unsigned char*) 0xF83)
#define TRISD (*(volatile __near unsigned char*) 0xF95) 

unsigned char num;

void ConfigurarLed(void){
TRISD = 0x00;
PORTD = 0xFF;

}
void LigarLed(unsigned char num){
    PORTD  |= ~(1 << num);
    
}
void DesligarLed(unsigned char num){
    PORTD  &= (1 << num);
    
}


 