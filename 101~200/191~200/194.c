#include <stdio.h>

#define x_i(x,i)printf("number of x%sisn %d.\n",3i,x##i)

void main(void)
{
    int xa = 3,xb = 5;

    x_i(x,a);
    x_i(x,b);
}
