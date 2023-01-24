#include <stdio.h>


typedef struct {
	char color[10];
	int x;
	int y;
} point_t;

void getPoint(point_t* points)
{

        
        printf("Enter point color:");
        scanf("%s", points->color);

        //get and print x and y
        printf("Enter point x:");
        scanf("%d", &points->x);


        printf("Enter point y:");
        scanf("%d", &points->y);

}


void printPoint(point_t points)
{
        printf("Color:%s\nx:%d\ny:%d\n", points.color, points.x, points.y);
}