#include <stdio.h>

void change_x1 (int x1);
void change_x2 (int *x2);

void main(void)
{
    int x;

    x = 5;
    printf("The value of x before calling the function:%d\n",x);

    change_x1(x);
    printf("The value of x after calling the function change_x1:%d\n",x);

    change_x2(&x);
    printf("The value of x after calling the function change_x2:%d\n",x);
}

void change_x1(int x1)
{
    x1 = 50;
}

void change_x2(int*x2)
{
    *x2 = 100;
}
