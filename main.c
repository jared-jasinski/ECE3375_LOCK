#include "address_map_arm.h"
#include "headers.h"

//returns true if password is correct, 0 otherwise
int CheckPassword(int inputPassword)
{
    if (inputPassword = password)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void SetPassword(int value, int nSet)
{
    password += value << nSet;
    nSet -= 4;
}

void InputPassword(int value, int nInput)
{
    passwordInput += value << nInput;
    nInput -= 4;
}

void clearPassword()
{
    nInput = 32;
    passwordInput &= 0x0000;
    DisplayHex(0);
}

void ChangePassword(void)
{
    nSet = 32;
}

int ReadButton(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

// this is how u initialize an external file "Display.c"
// void Display(int);
// then call it "Display(1234);"

int main(void)
{

    while (1)
    {

        while (nSet != 0)
        {
            //SetPassword();
            DisplayHex(password);
        }
        if (nInput != 0)
        {
            inputPassword();
            DisplayHex(inputPassword);
        }
    }
    return 0;
}