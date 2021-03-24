#include "address_map_arm.h"
#include "declarations.h"

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
