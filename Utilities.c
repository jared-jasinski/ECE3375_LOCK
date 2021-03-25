#include "headers.h"
int ReadButtons(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

volatile int *TIMER = (int *)TIMER_BASE;

void TimerCountDown(void)
{
    if (*TIMER == 0b11)
    {
        time++;
        *TIMER = 0;
    }
}


volatile int *TIMER_LVL = (int *)(TIMER_BASE + 0x8);
volatile int *TIMER_LVH = (int *)(TIMER_BASE + 0xc);

void InitTimer(int interval)
{
    *(TIMER_LVL) = interval;
    *(TIMER_LVH) = interval >> 16;
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