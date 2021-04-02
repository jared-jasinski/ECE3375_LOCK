#include "headers.h"


int ReadButton(void)
{
    volatile int button;
    button = *(PUSH_BUTTON) &= 0b1111111111; //and operation with the button bits & 1111
    return button;
}