#include<stdio.h>

#define COUNT 100

#if!defined COUNT
#define  COUNT 90
#endif

void main (void)
{
    printf("COUNT : %d\n",COUNT);
}
