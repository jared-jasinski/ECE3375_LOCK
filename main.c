#include "address_map_arm.h"
#include "headers.h"

int lookUpTable[10] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};

// this is how u initialize an external file "Display.c"
// void Display(int);
// then call it "Display(1234);"

int main(void)
{
    while (1)
    {

        while (nSet != 0)
        {
            //SetPassword();
            DisplayHex(password);
        }
        if (nInput != 0)
        {
            inputPassword();
            DisplayHex(inputPassword);
        }
    }
    return 0;
}