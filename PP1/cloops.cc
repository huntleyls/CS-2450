#include <stdio.h>

void printTriangle(int col)
{
    if(col < 1)
    {
        return;
    }
    int space = col - 1;
    while(space >= 1)
    {
        printf(" ");
        space--;
    }

    printf("+\n");
    if (col == 1)
    {
        return;
    }
    
    int column = col-1;
    int dashcount = 0;
   
    while(column - 1 > 0)
    {
        space = column - 1;
        while (space > 0)
        {
            printf(" ");
            space--;
        }
        printf("+");
        int dash = 0;
        while(dash < dashcount)
        {
            printf("-");
            dash++;
        }
        printf("+\n");
        column--;
        dashcount++;
    }
    int bl = 0;
    while (bl < col)
    {
        printf("+");
        bl++;
    }
    printf("\n");
    
}

void printRectangle(int row, int col)
{
    if(col< 1 || row < 1)
    {
        return;
    }
    
    int rows = row;
    int columns = col;
    for(int i = 0; rows > 0; i++)
    {
        printf("+");
        rows--;
    }
    printf("\n");
    if (col == 1)
    {
        return;
    }

    for(int j = 0; columns > 2; j++)
    {
        if(row > 1)
        {
            printf("+");
        }
        rows = row;
        for(int k = 0; rows > 2; k++)
        {
            printf("-");
            rows--;
        }
        printf("+");
        printf("\n");
        columns--;
    }
    rows = row;
    for(int l = 0; rows > 0; l++)
    {
        printf("+");
        rows--;
    }
    printf("\n");
}

void printFormat(int end, int col, int skip)
{
    int count = 1;
    int nlcount = 0;
    if(end < 1)
    {
        return;
    }

    if(col < 1 && 2 > skip)
    {
        while(count < end)
        {
            if(count == end)
            {
                printf("%d", count);
            }
            else
            {
                printf("%d\t", count);
            }
            count++;
        }

        printf("%d", end);
        printf("\n");
        
    }
    else if(col < 1 && 2 <= skip)
    {
        count = 1;
        while(count < end)
        {
            if(count % skip != 0)
            {
                if(count == end)
                {
                    printf("%d\n", count);
                }
                else
                {
                    printf("%d\t", count);
                }
            }
            count++;
        }
        if(count % skip != 0)
        {
            printf("%d", end);
            printf("\n");
        }
        
    }
    else if (col >= 1 && 2 > skip)
    {
        nlcount = 1;
        for(count = 1; count < end; count++)
        {
            
            if (nlcount % col != 0)
                {
                    printf("%d\t", count);
                }
                else {
                    printf("%d\n", count);
                }
            nlcount++;
        }

        printf("%d", end);
        printf("\n");
                 
    }
    else
    {
        nlcount = 0;
        for(count = 1; count < end; count++) 
        {
            
            if(count % skip != 0) 
            {
                nlcount++; 
                if (nlcount % col != 0)
                {
                    printf("%d\t", count);
                }
                else {
                    printf("%d\n", count);
                }
            }

        }
        if(count % skip != 0){
        printf("%d", end);
        printf("\n");
        }
        
        

    }
    
    

}