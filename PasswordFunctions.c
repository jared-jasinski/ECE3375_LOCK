#include "headers.h"

void ChangePassword()
{
//returns true if password is correct, 0 otherwise
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
    Display(0);
}
void changePass(int* passPtr){
    int newPass = 0;
    DisplayHexCode(0); // since the normal DisplayHex function i will convert any integer intput and write it as the integer that was passed in
    // i created this function to display various symbols, we can map the symbols in the array
    newPass = return8(0);
    *passPtr = newPass;

    
}

void passManager(int* passPtr){
volatile int* LED_ptr = 0xFF200000;
int mode = readIn();
if(mode == 10){
    *LED_ptr &= 0x01;
    changePass(passPtr);
    *LED_ptr = 0x00;
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