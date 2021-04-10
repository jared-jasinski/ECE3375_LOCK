#include "headers.h"

void ChangePassword(void)
{
    //returns true if password is correct, 0 otherwise
    nSet = 32;
    password &= 0x00000000;
}
int CheckPassword(int inputPassword, int *passwordPointer)
{
    if (inputPassword == *passwordPointer)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ClearPassword(void)
{
    nInput = 32;
    passwordInput &= 0x0000;
    Display(0);
}
void changePass(int *passPtr)
{
    void DisplayHexCode(int);
    int newPass = 0;
    DisplayHexCode(0); // since the normal DisplayHex function i will convert any integer intput and write it as the integer that was passed in
    // i created this function to display various symbols, we can map the symbols in the array
    newPass = return8(0);
    *passPtr = newPass;
}
//use the array to display symbols that are mapped in the array (eg, the 0x40 is a dash)
void DisplayHexCode(int input)
{

    volatile int *HEX0_ptr = HEX3_HEX0_BASE;
    volatile int *HEX4_ptr = HEX5_HEX4_BASE;

    volatile int lookUpTable[17] = {
        // same as Lab1
        0x40,
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

    };

    *HEX0_ptr = lookUpTable[input] + (lookUpTable[input] << 8) + (lookUpTable[input] << 16) + (lookUpTable[input] << 24);

    *HEX4_ptr = lookUpTable[input] + (lookUpTable[input] << 8) + (lookUpTable[input] << 16) + (lookUpTable[input] << 24);
}

void passManager(int *passPtr)
{
    volatile int *LED_ptr = 0xFF200000;
    int mode = readIn();
    if (mode == 10)
    {
        *LED_ptr &= 0x01;
        changePass(passPtr);
        *LED_ptr = 0x00;
    }
}
/* not sure if these are still used so i'm commenting it out
void SetPassword(int value, int nSet)
{
    password += value << nSet;
    nSet -= 4;
}

void InputPassword(int value, int nInput)
{
    passwordInput += value << nInput;
    nInput -= 4;
}*/