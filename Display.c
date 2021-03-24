#include "address_map_arm.h"

volatile int *hex0 = (int *)HEX3_HEX0_BASE;
volatile int *hex1 = (int *)HEX5_HEX4_BASE;

void Display(int value)
{
    int decVals[10];
    decVals[0] = 0x3F;
    decVals[1] = 0x6;
    decVals[2] = 0x5B;
    decVals[3] = 0x4F;
    decVals[4] = 0x66;
    decVals[5] = 0x6D;
    decVals[6] = 0x7D;
    decVals[7] = 0x7;
    decVals[8] = 0x7F;
    decVals[9] = 0x6F;

    // MM:SS:HH
    // i.e.: i = 4
    // 942069
    // 010000 = 940000
    // 940000 %
    // 100000
    // 4

    volatile int i;
    volatile int a = 0x0;
    volatile int b = 0x0;
    for (i = 5; i >= 0; i--)
    {
        int digit = (value % Exp(10, i + 1)) / (Exp(10, i));

        if (i > 3)
        {
            b <<= 8;
            b += decVals[digit];
        }
        else
        {
            a <<= 8;
            a += decVals[digit];
        }
    }
    *(hex0) = a;
    *(hex1) = b;
    return;
}

int Exp(int x, int y)
{
    volatile int result = 1;
    while (y != 0)
    {
        result *= x;
        y--;
    }
    return result;
}