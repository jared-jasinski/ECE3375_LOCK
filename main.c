#include "address_map_arm.h"
volatile int *HEX_SEC_HUND = (int *)HEX3_HEX0_BASE; //hex 0-3
volatile int *HEX_MINS = (int *)HEX5_HEX4_BASE;     //hex 4-5
volatile int *PUSH_BUTTON = (int *)KEY_BASE;

//Addresses for timer controls
volatile int *TIMER = (int *)TIMER_BASE;
volatile int *TIMER_CONTROL = (int *)(TIMER_BASE + 0x4);
volatile int *TIMER_LVL = (int *)(TIMER_BASE + 0x8);
volatile int *TIMER_LVH = (int *)(TIMER_BASE + 0xc);

//address for switch bank
volatile int *SWITCH_BANK = (int *)SW_BASE;

int passwordInput;
int password;
int nInput = 32;
int nSet = 32;

    int lookUpTable[10];
    lookUpTable[0] = 0x3F;
    lookUpTable[1] = 0x6;
    lookUpTable[2] = 0x5B;
    lookUpTable[3] = 0x4F;
    lookUpTable[4] = 0x66;
    lookUpTable[5] = 0x6D;
    lookUpTable[6] = 0x7D;
    lookUpTable[7] = 0x7;
    lookUpTable[8] = 0x7F;
    lookUpTable[9] = 0x6F;

void DisplayHex(int value)
{

}

//returns true if password is correct, 0 otherwise
void CheckPassword(void inputPassword){
    if(inputPassword = password){
        return 1;
    } else {
        return 0;
    }
}


void SetPassword{int value, int nSet){
    password += value << nSet;
    nSet-=4;
}


void InputPassword(int value,int nInput){
passwordInput += value << nInput;
nInput-=4;
}

void clearPassword(){
    nInput=32;
    passwordInput &= 0x0000;
    DisplayHex(0);
}

void ChangePassword(void){
    nSet=32;
}


int ReadButton(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

void main(void){

    while(1){

        while(nSet !=0){
            SetPassword();
            DisplayHex(password);
        }
        if(nInput!=0){
            inputPassword();
            DisplayHex(inputPassword);
        }






    }



}