#include "headers.h"

volatile int *hex0 = (int *)HEX3_HEX0_BASE;
volatile int *hex1 = (int *)HEX5_HEX4_BASE;

int GetPasswordInput()
{
    return passwordInput;
}

void ClearDisplay()
{
    /**
     * clears 8 hexdisplays to show nothing
     */
    *hex0 = 0x00000000;
    *hex1 = 0x00000000;
}

void LightShow()
{
    
        volatile int k;
        volatile int l;

        for (k = 0; k < 32; k++)
        {
            volatile int delay;
            for (delay = 0; delay < 10000; delay++)
                ;
            *LEDS = 1 << k;
        }
        for (l = 32; l > 0; l--)
        {
            volatile int delay;
            for (delay = 0; delay < 10000; delay++)
                ;
            *LEDS = 1 << l;
        }
}

void Display(int value)
{
    /**
     * displays up to an 8-digit value;
     * assumes "value" is in base10
     */

    volatile int i;
    volatile int a = 0x0;
    volatile int b = 0x0;
    for (i = 7; i >= 0; i--)
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

void DisplaySetPass(void)
{
    *hex1 = 0x6D797800; //SET
    *hex0 = 0x73776D6D; //PASS
}

void DisplayWrongPass(void)
{
    volatile int j;
    for (j = 0; j < 5; j++)
    {

        *hex1 = 0xFFFFFFFF; //all on
        *hex0 = 0xFFFFFFFF;

        // temp solution
        volatile int i;
        for (i = 0; i < 200000; i++)
            ;

        *hex1 = 0x00000000; //all off
        *hex0 = 0x00000000;

        for (i = 0; i < 200000; i++)
            ;
    }
}

void DisplayLocked(void)
{
    *hex0 = 0x3975795E;
    *hex1 = 0x0000385C;
}

void YouEnteredTheWrongPassIdiot(void)
{

    //LOCKED
    *hex0 = 0x3975795E;
    *hex1 = 0x0000385C;
    volatile int i;
    for (i = 0; i < 700000; i++)
        ;
    //OUT
    *hex0 = 0x005C3E78;
    *hex1 = 0x00000000;
    for (i = 0; i < 700000; i++)
        ;
    //30 SEC
    *hex0 = 0x006D7939;
    *hex1 = 0x00004F3F;
    for (i = 0; i < 700000; i++)
        ;
}

void DisplayAccessGranted(void)
{

    //ACCESS
    *hex0 = 0x39796D6D;
    *hex1 = 0x00007739;

    //delay loop
    volatile int i;
    for (i = 0; i < 700000; i++)
        ;

    //GRANTED
    *hex0 = 0x5478795E;
    *hex1 = 0x003D5077;
}

void UpdateDisplay(int digit)
{
    /**
     * takes a single digit and pushes to the right of the display;
     * preserving previously inputted digits
     */
    passwordInput *= 10;
    passwordInput += digit;
}
