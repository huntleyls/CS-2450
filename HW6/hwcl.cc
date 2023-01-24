#include <stdio.h>

void printRectangleWhile (int row, int column)
{
    if (row < 1 || column < 1) return;
    int  thisRow = row;
    int  thisCol = column;
    while (thisRow > 0)
    {
        printf("+");
        thisRow--;
    }
    printf("\n");
    if (column == 1) return;
    while(thisCol > 2)
    {
        if (row > 1) printf("+");
        thisRow = row;
        while (thisRow > 2)
        {
            printf("-");
            thisRow--;
        }
        printf("+\n");
        thisCol--;
    }
    thisRow = row;
    while (thisRow > 0)
    {
        printf("+");
        thisRow--;
    }
    printf("\n");
}

void printTriangleFor(int column)
{
    if (column < 1) return;
    for (int i = 0; i < column - 1; i++)
    {
        printf(" ");
    }
    printf("+\n");
    if (column == 1) return;
    int thisCol = 0;
    for (int j = column - 1; j > 1; j --)
    {
        for (int k = j -1; k > 0; k--)
        {
             printf(" ");
        }
        printf("+");
        for (int l = 0; l < thisCol; l++)
        {
            printf("-");
        }
        printf("+\n");
        thisCol++;
    }
    for (int m = 0; m < column; m++)
    {
        printf("+");
    }
    printf("\n");
}


    
