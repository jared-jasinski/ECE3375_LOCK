#include "headers.h"
void ChangePassword()
{
    nSet = 32;
    password &= 0x00000000;

}
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

void ClearPassword()
{
    nInput = 32;
    passwordInput &= 0x0000;
    DisplayHex(0);
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

