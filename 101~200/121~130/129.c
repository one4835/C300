#include <stdio.h>
#include <string.h>

typedef struct tagPoint
{
    int x;
    int Y;
}point;

void main (void)
{
    point pt = {5,10};
    char array[10];

    printf("x,y ;%d,%d\n",pt.x,pt.y);

    My_memset(&pt,0,sizeof(pt));

    printf("x,y:%d,%d\n",pt.x,pt.y);

    My_memset(array,48,sizeof(array));

    printf("array[0]~array[9]:%c~%c\n",array[0],array[9]);
}

void My_memset(void*dest,int c, unsigned count)
{
    while(count--)
    {
        *(char*)dest = c;
        dest = (char*)dest +1;
    }
}
