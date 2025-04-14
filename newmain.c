#include "config.h"
#include "led.h"


//inicio do programa
void main(void) {
char i;
float x;
ConfigurarLed();

for (;;) {  
for (i = 0; i < 8; i++){
     LigarLed(i);
for (x = 0; x <1000 ; x++);
   DesligarLed(i);
}
}
}