#include "address_map_arm.h"
extern volatile int passwordInput;
extern volatile int password;
extern volatile int nInput;
extern volatile int nSet;
extern volatile int lookUpTable[10];
extern volatile int time;
extern volatile int timeSec;
extern volatile int timeMin;
extern volatile int wrongAttempts;
extern volatile int buttonDown[32]; // edges and levels
extern volatile int buttonUp[32];
extern volatile int buttonPushed[32];

extern volatile int *HEX_SEC_HUND; //hex 0-3
extern volatile int *HEX_MINS;     //hex 4-5
extern volatile int *PUSH_BUTTON;

//Addresses for timer controls
extern volatile int *TIMER;
extern volatile int *TIMER_CONTROL;
extern volatile int *TIMER_LVL;
extern volatile int *TIMER_LVH;

//address for switch bank
extern volatile int *SWITCH_BANK;

// prototyping function calls
void ChangePassword();
int CheckPassword(int, int*);
void ClearPassword();
void SetPassword(int, int);
void InputPassword(int, int);
int readButtons();
void TimerCountDown();
void InitTimer();
int Exponent();
void Display();
void UpdateDisplay(int);
void DisplaySetPass();
void DisplayWrongPass();
void AccessGranted();
