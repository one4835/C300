#include<stdio.h>

typedef union tagVariable
{
    int i;
    double d;
}VA;

void main(void)
{
    VA=va;

    va.i = 5;

    printf("va.i's size : %d\n",va.i);

    va.d = 3.14;

    printf("va.d's size : %d\n",va.d);
    printf("va.i's size : %d\n",va.i);
}
