#include "headers.h"

int ReadButton(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

int buttonOut(int in)
{
    /**
     * returns output from push buttons as corresponding
     * num pad value
     */
    if (in == 0)
    {
        return 0;
    }

    if ((in & 0x01) == 1)
    {
        return 1;
    }

    if ((in & 0x02) == 2)
    {
        return 2;
    }

    if ((in & 0x04) == 4)
    {
        return 3;
    }

    if ((in & 0x08) == 8)
    {
        return 4;
    }

    if ((in & 0x016) == 16)
    {
        return 5;
    }

    if ((in & 0x32) == 32)
    {
        return 6;
    }

    if ((in & 0x64) == 64)
    {
        return 7;
    }

    if ((in & 0x80) == 128)
    {
        return 8;
    }

    if ((in & 0x100) == 256)
    {
        return 9;
    }

    if ((in & 0x200) == 512)
    {
        return 10;
    }
}


int CountDigits(int n)
{
    /** 
     * returns number of digits
    */
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

int readIn()
{
    volatile int *buttons = KEY_BASE; // pointer pointing to the buttons
    int output;

    volatile int DELAY_LENGTH = 500000;
    volatile int delay_count;
    int in = *buttons;
    for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count)
        output = buttonOut(in);

    return (output);
}

int return8(int temp)
{
    int in = readIn();
    int prev;

    while (in == 0)
    {
        in = readIn();
    }

    if (digits(temp) == 8)
    {
        return temp;
    }
    else
    {
        temp = temp * 10 + in;
        DisplayHex(temp);

        return return8(temp);
    }
}
