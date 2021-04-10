#include "address_map_arm.h"
#include "headers.h"

volatile int passwordInput = 0;
volatile int password = 0;
volatile int nInput = 0;
volatile int nSet = 0;
volatile int lookUpTable[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};
volatile int time = 0;
volatile int timeSec = 0;
volatile int timeMin = 0;
volatile int buttonDown[32] = {0}; // edges and levels
volatile int buttonUp[32] = {0};
volatile int buttonPushed[32] = {0};

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

// this is how u initialize an external file "Display.c"
// void Display(int);
// then call it "Display(1234);"

void Display(int);
void InputPassword(int, int);
int readButtons();

int main(void)
{
    InitTimer(1000000);
    while (1)
    {
        // test: display input from buttons
        if (1)
        {
            // passwordInput = readButtons();
            UpdateDisplay(1);
            Display(passwordInput);
        }
        volatile int i;
        for (i = 0; i < 700000; i++)
            ;
    }
    return 0;
}