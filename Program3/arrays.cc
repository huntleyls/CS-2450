#include <stdio.h>


double findCloseToZero(double myArray[], int numItems)
{   
    int i =0;
    int ctz = 0;	
    for(i = 0; i< numItems; i++)
    {
        double last = myArray[ctz];
        double cur = myArray[i];
 
        if(cur < 0)
        {
            cur = cur * (-1);
        }
        if(myArray[ctz] < 0)
        {
            last = last * -1; ;
        }
        if(cur < last)
        {
            ctz = i;
        }
    }
    return myArray[ctz];

}
double findFarFromZero(double myArray[], int numItems)
{
    int i = 0;
    double far = myArray[0];
	
    for(i = 0; i < numItems; i++)
    {
        if(myArray[i] < 0)
        {
            far = myArray[i];
        }
		
        if(myArray[i] > far)
        {
            far = myArray[i];
        }
    }
    return far;
}   

int countDivisible(int myArray[], int numItems, int dv)
{
    int i = 0;
    int c = 0;
	
    for (i = 0; i < numItems; i ++)
    {
        if (myArray[i] % dv  == 0)
        {
            c++;
        }
    }
	
    return c;
}

int countWholenumbers(double myArray[], int numItems)
{
    int i = 0;
    int c = 0;
	
    for (i = 0; i < numItems; i++)
    {
        if (((int)myArray[i] % 2) == 0.0)
        {
            c++;
        }
    }
	
    return c;

}
double sumFractions(double myArray[], int numItems)
{
    double sum = 0;
    double newnumItems = 0.0;
	
    for (int i = 0; i < numItems; i++)
    {
        int numItems = (int)myArray[i];
        newnumItems = myArray[i] - numItems;
        sum += newnumItems;
    }
	
    return sum;
}

int countAbsoluteRangeValues(double myArray[], int numItems, double value)
{
    
    int c = 0;
    if(value < 0)
    {
        value = value * (-1);
    }
    for (int i = 0; i < numItems; i++)
     {
         double cur = myArray[i];
         if(cur < 0)
         {
             cur = cur * (-1);
         }
         if (cur < (value + .5) && cur > (value - .5))
         {
             c++;
         }
     }
     return c;
}
