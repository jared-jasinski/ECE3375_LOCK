#include "headers.h"

void disableTimer(void);
void StartTimer(void);

int ReadButtons(void)
{
    volatile int button;
    button = *PUSH_BUTTON &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

void TimerCountDown(void)
{
    if ((*TIMER & 0x1) == 0b1)
    {
        time++;
    }
        *TIMER = 0x0;
        StartTimer();
}

void WrongPassTracker(void)
{
    if (wrongAttempts < 3)
        return;
    else
    {
        disableTimer();
        wrongAttempts = 0;
    }
}

void IncrementTime(void)
{
    if (time > 99)
    {
        timeSec++;
        time = 0;
    }
}

void StartTimer(void)
{
    //toggles start bit
    *(TIMER_CONTROL) = 0b100;
}

void disableTimer(void)
{
    InitTimer();
    StartTimer(); //starts the timer
    while (timeSec < 30)
    {
        IncrementTime();
        TimerCountDown();
        YouEnteredTheWrongPassIdiot(); //30 second lock out in the while loop
    }
    timeSec = 0;
}

void InitTimer(void)
{
    *(TIMER_LVL) = 0x4240;
    *(TIMER_LVH) = 0xF;
}

int Exponent(int base, int exponent)
{
    volatile int result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}

void ShortDelay(void)
{
    volatile int i;
    for (i = 0; i < 1000000; i++)
        ;
}