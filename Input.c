#include "headers.h"

int ReadButton(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
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
