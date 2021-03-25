#include 'address_map_arm.h'
extern int passwordInput;
extern int password;
extern int nInput;
extern int nSet;
extern int lookUpTable[10];
extern int time;


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
