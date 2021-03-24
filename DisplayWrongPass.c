#include "declarations.h"
void DisplayWrongPass(void){
*HEX_47 = 0xFFFFFFFF; //all on
*HEX_03 = 0xFFFFFFFF; 

//need timer to flash

*HEX_47 = 0x00000000; //all on
*HEX_03 = 0x00000000; 
}