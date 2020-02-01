#include<stdio.h>

typedef union tagVariable
{
    int i;
    double d;
}VA;

void print (VA*pva);

void main(void)
{
    VA va;

    print(&va);
}

void print(VA*pva)
{
    pva->i = 5;

    printf("pva->i's size : %d\n",va.i);

    pva->d = 3.14;

    printf("pva->d's size : %d\n",va.d);
    printf("pva->i's size : %d\n",va.i);
}
