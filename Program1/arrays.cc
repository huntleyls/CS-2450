#include <stdio.h>
double getPositiveAverage(double array[], int numItems)
{
    double avg = 0;
    int numofitems = 0;

    for (int i = numItems-1; i >= 0; i--)
    {
        if (array[i] > 0)
        {
            avg = avg + array[i];
            numofitems++;
        }
    }
    if (numofitems == 0) {
        return 0;
    }
    else {
        return avg/numofitems;
    }
}

int countRangeValues(double array[], int numItems, double count)
{
    double countp = count + .5;
    double countm = count - .5;
    int counter = 0;

    for (int i = numItems-1; i >= 0; i--)
    {
        if ((array[i] >= countm) && (array[i] < countp))
        {
            counter++;
        }
    }

    return counter;
}

double getMaxAbsolute(double array[], int numItems)
{
    double max = 0;

    for (int i = numItems-1; i >= 0; i--)
    {
        if (array[i] == max * -1 && array[i] > 0)
        {
            max = array[i];
        }
        else if (array[i] < 0)
        {
            if (max < 0)
            {
                if ((array[i] * -1) > (max * -1))
                {
                    max = array[i];
                }
            }
            else
            {
                if ((array[i] * -1) > max)
                {
                    max = array[i];
                }
            }
        }
        else
        {
            if (max < 0)
            {
                if ((array[i]) > (max * -1))
                {
                    max = array[i];
                }
            }
            else
            {
                if ((array[i]) > max)
                {
                    max = array[i];
                }
            }
        }
    }


    return max;
}

int countInverses(int array[], int numItems)
{
 int count = 0;

    for (int i = 0; i < numItems; i++)
        for (int j = i + 1; j < numItems; j++)
            if (array[i] + array[j] == 0 && array[i] != 0 && array[j] != 0)
            {
                //printf("%d\n", count);
                array[i] = 0;
                array[j] = 0;
                count++;
            }

    //printf("%d\n", count);
    return count;
}
int getMaxCount(double array[], int numItems)
{
    return countRangeValues(array, numItems, getMaxAbsolute(array, numItems));
}