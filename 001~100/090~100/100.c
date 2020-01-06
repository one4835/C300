#include <stdio.h>
#include <string.h>

struct tag M1
{
    int x;
    int y;
    char buffer[30];
};

void main(void)
{
    struct tagM1 x1,x2;

    x1.x = 5;
    x1.y = 10;
    strcpy(&x2,&x1,sizeof(x1));

    memcpy(&x2,&x1,sizeof(x1));

    puts(x2,buffer);
}
