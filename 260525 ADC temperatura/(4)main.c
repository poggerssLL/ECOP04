#include "lcd.h"
#include "config.h"
#include "pic18f4520.h"
#include "adc.h"
#include "pwm.h"
#include "keypad.h"
#include "tempcontrol.h"
int temp, Set1 = 0, Set2 = 0;
unsigned int tecla = 16;
unsigned int inferior = 25;
unsigned int superior = 50;

void PrintInt(int temp){
    lcdCommand(0x80);
    lcdData('C');
    lcdData(((temp/1000)%10)+ 48 );
    lcdData(((temp/100)%10)+ 48 );
    lcdData(((temp/10)%10)+ 48 );
    lcdData(((temp)%10) + 48 );
}
int LeTemperatura(void){
    int temperatura;
    temperatura = adcRead();
    temperatura = temperatura*2;
    return temperatura;
}
void main(void){
    adcInit();
    lcdInit();
    pwmInit();
    kpInit();
    pwmFrequency(1000);
    for(;;){
     temp = LeTemperatura();
        PrintInt(temp);
        ConfigurarLimiteSuperior(superior);
        ConfigurarLimiteInferior(inferior);
        lcdData('H');
    lcdData(((superior/1000)%10)+ 48 );
    lcdData(((superior/100)%10)+ 48 );
    lcdData(((superior/10)%10)+ 48 );
    lcdData(((superior)%10) + 48 );
    lcdData('L');
    lcdData(((inferior/1000)%10)+ 48 );
    lcdData(((inferior/100)%10)+ 48 );
    lcdData(((inferior/10)%10)+ 48 );
    lcdData(((inferior)%10) + 48 );
    lcdCommand(0xC0);
    AtualizarSistema();
        /*kpDebounce();
        if(kpRead() != tecla){
            tecla = kpRead();
            
            if(BitTst(tecla, 2)){
                pwmSet1(100);
            }
            if(BitTst(tecla,3)){
                pwmSet1(0);
            }
            if(BitTst(tecla,4)){
                pwmSet2(100);
            }
            if(BitTst(tecla,5)){
                pwmSet2(0);
            }
        }
        */
        
    }
}
