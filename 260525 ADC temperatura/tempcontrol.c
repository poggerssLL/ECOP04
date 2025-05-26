#include "tempcontrol.h"
#include "adc.h"
#include "pwm.h"
unsigned char tempS;
unsigned char tempI;

void ConfigurarLimiteSuperior(unsigned char temp){
    tempS =  temp;
}
void ConfigurarLimiteInferior(unsigned char temp){
    tempI = temp;
}

void AtualizarSistema(void){
    int temp;
    temp = adcRead()/2;
    if(temp<tempI){
        pwmSet2(100);
        pwmSet1(0);
    }
    if((temp>tempI) && (temp<tempS)){
        pwmSet1(0);
        pwmSet2(0);
    }
    if(temp>tempS){
        pwmSet1(100);
        pwmSet2(0);
    }
    
    
}
