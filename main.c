#include "address_map_arm.h"
#include "headers.h"

volatile int passwordInput = 0;
volatile int password = 12345678;
volatile int nInput = 0;
volatile int nSet = 0;
volatile int lookUpTable[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};
volatile int time = 0;
volatile int timeSec = 0;
volatile int timeMin = 0;
volatile int buttonDown[32] = {0}; // edges and levels
volatile int buttonUp[32] = {0};
volatile int buttonPushed[32] = {0};
volatile int state = 1;
volatile int passwordError = 0;
volatile int passwordAccept = 0;
volatile int wrongAttempts = 0;

volatile int *HEX_SEC_HUND = (int *)HEX3_HEX0_BASE; //hex 0-3
volatile int *HEX_MINS = (int *)HEX5_HEX4_BASE;     //hex 4-5
volatile int *PUSH_BUTTON = (int *)KEY_BASE;
volatile int *LEDS = (int *)LED_BASE;

//Addresses for timer controls
volatile int *TIMER = (int *)TIMER_BASE;
volatile int *TIMER_CONTROL = (int *)(TIMER_BASE + 0x4);
volatile int *TIMER_LVL = (int *)(TIMER_BASE + 0x8);
volatile int *TIMER_LVH = (int *)(TIMER_BASE + 0xc);

//address for switch bank
volatile int *SWITCH_BANK = (int *)SW_BASE;

// this is how u initialize an external file "Display.c"
// void Display(int);
// then call it "Display(1234);"

void Display(int);
void InputPassword(int, int);
int readButtons();
void DisplayState(int);
void WrongPassTracker(void);
void disableTimer(void);
void LightShow(void);

int main(void)
{
    InitTimer(1000000);
    while (1)
    {
        UpdateButtons();

        // locked state
        if (state == 0)
        {
            if (CountDigits(GetPasswordInput()) == 8)
            {
                if (!CheckPassword())
                {
                    passwordError = 1;
                    passwordInput = 0;
                    wrongAttempts++;
                    WrongPassTracker();
                }
                else
                {
                    passwordInput = 0;
                    DisplayAccessGranted();
                    ShortDelay();
                    ClearDisplay();
                    state = 1;
                }
            }
            volatile int i;
            for (i = 0; i < 9; i++)
            {
                if (buttonDown[i])
                {
                    UpdateDisplay(i + 1);
                }
            }
        }

        // unlocked
        else if (state == 1)
        {
            ClearDisplay();
            wrongAttempts = 0;
            if (buttonDown[0])
            {
                state = 0;
                ClearLED();
            }
            else if (buttonDown[1])
            {
                state = 2;
                ClearLED();
            }
        }

        // reset password state
        else if (state == 2)
        {
            if (CountDigits(GetPasswordInput()) == 8)
            {
                password = passwordInput;
                passwordInput = 0;
                ShortDelay();
                state = 0;
            }
            volatile int i;
            for (i = 0; i < 9; i++)
            {
                if (buttonDown[i])
                {
                    UpdateDisplay(i + 1);
                }
            }
        }

        // timeout state
        else if (state == 3)
        {
        }

        DisplayState(state);
    }
    return 0;
}

void DisplayState(int state)
{

    // locked state
    if (state == 0)
    {
        if (passwordError)
        {
            DisplayWrongPass();
            ShortDelay();
            passwordError = 0;
        }
        else if (passwordInput == 0 && !passwordError)
            DisplayLocked();
        else
            Display(passwordInput);
    }

    // unlocked
    else if (state == 1)
    {
        LightShow();
    }

    // reset password state
    else if (state == 2)
    {
        if (passwordInput == 0)
            DisplaySetPass();
        else
            Display(passwordInput);
    }

    // timeout state
    else if (state == 3)
    {
    }
}