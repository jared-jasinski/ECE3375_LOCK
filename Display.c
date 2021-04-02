#include "headers.h"

volatile int *hex0 = (int *)HEX3_HEX0_BASE;
volatile int *hex1 = (int *)HEX5_HEX4_BASE;

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

void UpdateDisplay(int digit) {
    input *= 10;
    input += digit;
}

void DisplaySetPass(void)
{
    *hex1 = 0x6D797800; //SET
    *hex0 = 0x73776D6D; //PASS
}

void DisplayWrongPass(void)
{
    int i = 0;

    for (i = 0; i < 10; i++)
    {

        *hex1 = 0xFFFFFFFF; //all on
        *hex1 = 0xFFFFFFFF;
        FlashDelay();
        while (!DelayChecker())
            ;
        StopTimer();

        *hex1 = 0x00000000; //all off
        *hex0 = 0x00000000;
        FlashDelay();
        while (!DelayChecker())
            ;
        StopTimer();
    }
}

void AccessGranted(void)
{

    //ACCESS
    *hex0 = 0x39796D6D;
    *hex1 = 0x00007739;

    HalfSecondDelay();
    while (!DelayChecker())
        ;
    StopTimer();

    //GRANTED
    *hex0 = 0x5478795E;
    *hex1 = 0x003D5077;
}