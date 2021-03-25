#include "headers.h"
volatile int *hex0 = (int *)HEX3_HEX0_BASE;
volatile int *hex1 = (int *)HEX5_HEX4_BASE;

int Exponent(int);

void Display(int value)
{
    volatile int i;
    volatile int a = 0x0;
    volatile int b = 0x0;
    for (i = 5; i >= 0; i--)
    {
        int digit = (value % Exponent(10, i + 1)) / (Exponent(10, i));

        if (i > 3)
        {
            b <<= 8;
            b += lookUpTable[digit];
        }
        else
        {
            a <<= 8;
            a += lookUpTable[digit];
        }
    }
    *(hex0) = a;
    *(hex1) = b;
    return;
}

void DisplaySetPass(void){
*HEX_47 = 0x6D797800; //SET

*HEX_03 = 0x73776D6D; //PASS
}

void DisplayWrongPass(void){
*HEX_47 = 0xFFFFFFFF; //all on
*HEX_03 = 0xFFFFFFFF; 

//need timer to flash

*HEX_47 = 0x00000000; //all on
*HEX_03 = 0x00000000; 
}

void AccessGranted(void){

//ACCESS
*HEX_03 = 0x39796D6D;
*HEX_47 = 0x00007739;

//NEED TIMER BETWEEN WORDS

//GRANTED
*HEX_03 = 0x5478795E;
*HEX_47 = 0x003D5077;

}