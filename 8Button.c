#define HEX3_HEX0_BASE 0xFF200020
#define HEX5_HEX4_BASE 0xFF200030
#define KEY_BASE 0xFF200050

void DisplayHex(int input)
{
    volatile int *HEX0_ptr = HEX3_HEX0_BASE;
    volatile int *HEX4_ptr = HEX5_HEX4_BASE;

    volatile int disp01 = (input / 1000000);
    volatile int disp23 = (input / 10000) % 100;
    volatile int disp45 = (input / 100) % 100;
    volatile int disp67 = input % 100;

    volatile int d6 = disp67 % 10;
    volatile int d7 = ((disp67 - d6) / 10);
    volatile int d2 = disp23 % 10;
    volatile int d3 = ((disp23 - d2) / 10);
    volatile int d4 = disp45 % 10;
    volatile int d5 = (disp45 - d4) / 10;
    volatile int d0 = disp01 % 10;
    volatile int d1 = (disp01 - d0) / 10;

    volatile int lookUpTable[16] = {
        // same as Lab1
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // .
        0x66, // .
        0x6D, // .
        0x7D, // .
        0x07, // .
        0x7F, // 8
        0x6F, // 9
        0x77, // A
        0x7C, // B
        0x39, // C
        0x5E, // D
        0x79, // E
        0x71, // F

    };

    *HEX0_ptr = lookUpTable[d6] + (lookUpTable[d7] << 8) + (lookUpTable[d4] << 16) + (lookUpTable[d5] << 24);

    *HEX4_ptr = lookUpTable[d2] + (lookUpTable[d3] << 8) + (lookUpTable[d0] << 16) + (lookUpTable[d1] << 24);
}
int buttonOut(int in)
{

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

int digits(int n)
{
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
    volatile int *LED_ptr = 0xFF200000;
    volatile int *buttons = KEY_BASE; // pointer pointing to the buttons
    int output;

    volatile int DELAY_LENGTH = 500000;
    volatile int delay_count;
    int in = *buttons;
    for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count)
        output = buttonOut(in);

    return (output);
    output = 0;
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