#include "stdio.h"
#include "lcd.h"
#include "pic18f4520.h"

void printf(char *string){
    
    for(int i = 0; i <31; i++){
        if(string[i] == '\n'){
            lcdCommand(0xC0);           
        }
        else if(string[i] == '\0') {            
            return;
        }
        else {
            lcdData(string[i]);
        }
    }
}

