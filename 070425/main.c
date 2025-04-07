#include "config.h"
#include "pic18f4520.h"
#include "lcd.h"
#include "stdio.h"
//inicio do programa
void main(void) {
 lcdInit();
 lcdCommand(0x80);
 
 printf("ECOP14\nIESTI UNIFEI");
}
