#include "headers.h"

int ReadButton(int index)
{
    /**
     * reads the value of a single button at the specified index
     */
    volatile int button;
    button = *(PUSH_BUTTON) &= 1 << index;
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

int readIn(void)
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

    if (CountDigits(temp) == 8)
    {
        return temp;
    }
    else
    {
        temp = temp * 10 + in;

        return return8(temp);
    }
}

void UpdateButtons(void)
{
    // update level
    volatile int i;
    for (i = 0; i < 32; i++)
    {
        if (ReadButton(i))
        {   
            // buttonDown
            if (!buttonPushed[i]) {
                buttonDown[i] = 1;
            }
            else {
                buttonDown[i] = 0;
                buttonUp[i] = 0;
            }
            buttonPushed[i] = 1;
        }
        else
        {
            // buttonUp
            if (buttonPushed[i])
            {
                buttonUp[i] = 1;
            }
            else
            {
                buttonDown[i] = 0;
                buttonUp[i] = 0;
            }
            buttonPushed[i] = 0;
        }
    }
    // update button edges
}