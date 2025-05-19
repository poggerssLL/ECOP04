/*#include "pic18f4520.h"
#include "config.h"
#include "lcd.h"
#include "rtc.h"
void main(void) {
float i;
//Inicializacoes
lcdInit();
rtcInit();
//Escreve data/hora no RTC
rtcPutSeconds(0);
rtcPutMinutes(0);
rtcPutHours(0);
for (;;) {
//Le horario do RTC
lcdCommand(0x80);
lcdData(((rtcGetHours() / 10) % 10) + 48);
lcdData((rtcGetHours() % 10) + 48);
lcdData(':');
lcdData(((rtcGetMinutes() / 10) % 10) + 48);
lcdData((rtcGetMinutes() % 10) + 48);
lcdData(':');
lcdData(((rtcGetSeconds() / 10) % 10) + 48);
lcdData((rtcGetSeconds() % 10) + 48);
for (i = 0; i < 1000; i++);
}
}*/

/*#include "config.h"
#include "lcd.h"
#include "rtc.h"
#include "serial.h"
void main(void) {
float i;
unsigned char dadoSerial;
//Inicializacoes
lcdInit();
serialInit();
rtcInit();
for (;;) {
dadoSerial = serialRead();
if(dadoSerial != 0){ //Se dado e valido
switch(dadoSerial){
case 'H':
rtcPutHours(rtcGetHours()+1);
break;
case 'h':
rtcPutHours(rtcGetHours()-1);
break;
case 'M':
rtcPutMinutes(rtcGetMinutes()+1);
break;
case 'm':
rtcPutMinutes(rtcGetMinutes()-1);
break;
}
}
//Le horario do RTC
lcdCommand(0x80);
lcdData(((rtcGetHours() / 10) % 10) + 48);
lcdData((rtcGetHours() % 10) + 48);
lcdData(':');
lcdData(((rtcGetMinutes() / 10) % 10) + 48);
lcdData((rtcGetMinutes() % 10) + 48);
lcdData(':');
lcdData(((rtcGetSeconds() / 10) % 10) + 48);
lcdData((rtcGetSeconds() % 10) + 48);
for (i = 0; i < 1000; i++);
}
}*/
#include "config.h"
#include "lcd.h"
#include "rtc.h"
#include "serial.h"

void main(void) {
    float i;
    unsigned char dadoSerial;
    unsigned char comando[7];
    unsigned char pos = 0;
    unsigned char horaData = 0;
    lcdInit();
    serialInit();
    rtcInit();
    for (;;) {
        dadoSerial = serialRead();
        if (dadoSerial != 0) {
            if (pos == 0) {
                if (dadoSerial == 'D') {
                    horaData = 0;
                } else if (dadoSerial == 'H') {
                    horaData = 1;
                }
            }
            if (pos < 8) {
                comando[pos] = dadoSerial;
                pos++;
            }
            if (pos == 7) {
                if (horaData == 0) {
                    unsigned char dia = (comando[1] - '0') * 10 + (comando[2] - '0');
                    unsigned char mes = (comando[3] - '0') * 10 + (comando[4] - '0');
                    unsigned char ano = (comando[5] - '0') * 10 + (comando[6] - '0');
                    rtcPutDate(dia);
                    rtcPutMonth(mes);
                    rtcPutYear(ano);
                    lcdCommand(0xC0); 
                    lcdData((dia / 10) + '0');
                    lcdData((dia % 10) + '0');
                    lcdData('/');
                    lcdData((mes / 10) + '0');
                    lcdData((mes % 10) + '0');
                    lcdData('/');
                    lcdData((ano / 10) + '0');
                    lcdData((ano % 10) + '0');
                } else if (horaData == 1) {
                    unsigned char hora = (comando[1] - '0') * 10 + (comando[2] - '0');
                    unsigned char minuto = (comando[3] - '0') * 10 + (comando[4] - '0');
                    unsigned char segundo = (comando[5] - '0') * 10 + (comando[6] - '0');
                    rtcPutHours(hora);
                    rtcPutMinutes(minuto);
                    rtcPutSeconds(segundo);
                    lcdCommand(0x80);
                    lcdData(((rtcGetHours() / 10) % 10) + '0'); 
                    lcdData((rtcGetHours() % 10) + '0');
                    lcdData(':');
                    lcdData(((rtcGetMinutes() / 10) % 10) + '0');
                    lcdData((rtcGetMinutes() % 10) + '0'); 
                    lcdData(':');
                    lcdData(((rtcGetSeconds() / 10) % 10) + '0');
                    lcdData((rtcGetSeconds() % 10) + '0');
                }
                pos = 0;
                horaData = 0;  
            }
        }
        lcdCommand(0x80);  
        lcdData(((rtcGetHours() / 10) % 10) + '0');  
        lcdData((rtcGetHours() % 10) + '0');        
        lcdData(':');
        lcdData(((rtcGetMinutes() / 10) % 10) + '0');  
        lcdData((rtcGetMinutes() % 10) + '0');       
        lcdData(':');
        lcdData(((rtcGetSeconds() / 10) % 10) + '0'); 
        lcdData((rtcGetSeconds() % 10) + '0');
        lcdCommand(0xC0);
        unsigned char dia = rtcGetDate();
        unsigned char mes = rtcGetMonth();
        unsigned char ano = rtcGetYear();
        lcdData((dia / 10) + '0');
        lcdData((dia % 10) + '0');
        lcdData('/');
        lcdData((mes / 10) + '0');
        lcdData((mes % 10) + '0');
        lcdData('/');
        lcdData((ano / 10) + '0');
        lcdData((ano % 10) + '0');
        for (i = 0; i < 1000; i++);
    }
}
