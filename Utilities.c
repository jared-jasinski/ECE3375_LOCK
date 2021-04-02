#include "headers.h"
int ReadButtons(void)
{
    volatile int button;
    button = *PUSH_BUTTON &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}

void TimerCountDown(void)
{
    if (*TIMER == 0b11)
    {
        time++;
        *TIMER = 0;
    }
}

int DelayChecker(void){
        if (*TIMER == 0b11){
            return 1;
        }else{
            return 0;
        }
}


 void IncrementTime(void){
       if(time > 99){
           timeSec++;
           time = 0;
           if(timeSec >=60){
               timeSec = 0;
               timeMin++;
           }
       }
 }

 void HalfSecondDelay(void){
     InitTimer(500000000);
 }

 void FlashDelay(void){
     InitTimer(50000000);
 }


void StopTimer(void)
{
    *(TIMER_CONTROL) = 8;
}

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