#include "address_map_arm.h"
extern int passwordInput;
extern int password;
extern int nInput;
extern int nSet;
extern int lookUpTable[10];
extern int time;
extern int timeSec;
extern int timeMin;

extern volatile int *HEX_SEC_HUND = (int *)HEX3_HEX0_BASE; //hex 0-3
extern volatile int *HEX_MINS = (int *)HEX5_HEX4_BASE;     //hex 4-5
extern volatile int *PUSH_BUTTON = (int *)KEY_BASE;

//Addresses for timer controls
extern volatile int *TIMER = (int *)TIMER_BASE;
extern volatile int *TIMER_CONTROL = (int *)(TIMER_BASE + 0x4);
extern volatile int *TIMER_LVL = (int *)(TIMER_BASE + 0x8);
extern volatile int *TIMER_LVH = (int *)(TIMER_BASE + 0xc);

//address for switch bank
extern volatile int *SWITCH_BANK = (int *)SW_BASE;

extern int passwordInput;
extern int password;
extern int nInput = 32;
extern int nSet = 32;

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


// prototyping function calls 
void ChangePassword();
int CheckPassword(int );
void ClearPassword();
void SetPassword(int , int );
void InputPassword(int , int );
int readButtons();
void TimerCountDown();
void InitTimer();
int Exponent();
void Display();
void DisplaySetPass();
void DisplayWrongPass();
void AccessGranted();