#include <stdio.h>



typedef struct
{
        char color[10];
        int x;
        int y;
} point_t;
//getPoint and printPoint here.
void getPoint(point_t *points);
void printPoint(point_t points);

int main()
{
 point_t p1;


//Call getPoint passing a pointer to p1 (by reference)
getPoint(&p1);

// //Call printPoint passing p1 by value.
printPoint(p1);
}