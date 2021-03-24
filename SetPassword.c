void SetPassword(int value, int nSet)
{
    password += value << nSet;
    nSet -= 4;
}