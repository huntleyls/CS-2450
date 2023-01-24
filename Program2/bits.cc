#include <stdio.h> 

int getMask(int sbit, int ebit, int bv)
{
    int mask = 0;
    int sv = 1;
    if(sbit < 0 || ebit > 31)
        return 0;
    if (sbit > ebit)
        return 0;
    if (bv != 0 && bv != 1)
        return 0;
    for (int i = 0; i <= 32; i++)
    {
        if (i >= sbit && i <= ebit) 
               mask  = mask | sv;
         sv = sv << 1;


    }
    if (bv == 0)
    {
        return ~mask;
    }    
    return mask;
    
}

int getSubInt(int sb, int eb, int val)
{
    int mask = getMask (sb, eb, 1);
    unsigned int rValue = val & mask;
    rValue = rValue >> sb;
    return rValue;
}

void printDashHex(int val)
{
    int mask = 0xF0000000;
    int stVal[8];
    for (int i = 0; i < 8; i++)
    {
        stVal[i] = (unsigned)(val & mask) >> 28;
        val = val << 4;
    }
    for (int i = 0; i < 15; i++)
    {
        if (i % 2 == 0)
            printf("%X", stVal[i/2]);
        else
            printf("-");
    }
    printf("\n");
}
