#include "declarations.h"
void AccessGranted(void){

//ACCESS
*HEX_03 = 0x39796D6D;
*HEX_47 = 0x00007739;

//NEED TIMER BETWEEN WORDS

//GRANTED
*HEX_03 = 0x5478795E;
*HEX_47 = 0x003D5077;

}