#include <stdio.h>

void main(void)
{
    int x = 0,y = 0;
    int*pxy[2];

    pxy[0] = &x;
    pxy[1] = &y;

    *pxy[0] = 5;
    *pxy[1] = 10;

    printf("x = %d,pxy[0]= %d\n",x,*pxy[0]);
    printf("x = %d,pxy[1]= %d\n",y,*pxy[1]);

    printf("x + y = %d\n",x + y);
    printf("x + y = %d\n",pxy[0] +*pxy[1]);
}
