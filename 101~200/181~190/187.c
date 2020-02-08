#include <stdio.h>
#include <math.h>

void main(void)
{
    double x = 2.3,n,y;

    y = modf(x,&n);

    printf("num %g,%g\n",n,y);
}
