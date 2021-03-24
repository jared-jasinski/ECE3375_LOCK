#include "address_map_arm.h"
#include "declarations.h"

volatile int *TIMER_LVL = (int *)(TIMER_BASE + 0x8);
volatile int *TIMER_LVH = (int *)(TIMER_BASE + 0xc);

void InitTimer(int interval)
{
    *(TIMER_LVL) = interval;
    *(TIMER_LVH) = interval >> 16;
}



