#include "declarations.h"
volatile int *TIMER = (int *)TIMER_BASE;

void TimerCountDown(void)
{
    if (*TIMER == 0b11)
    {
        time++;
        *TIMER = 0;
    }
}