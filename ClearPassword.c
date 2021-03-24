#include "declarations.h"
void ClearPassword()
{
    nInput = 32;
    passwordInput &= 0x0000;
    DisplayHex(0);
}