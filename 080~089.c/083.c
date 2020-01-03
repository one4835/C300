#include<stdio.h>
#include<stdilb.h>

void main(void)
{
    int value;
    char string[100];
    int radix;

    radix = 10;

    value = 5;
    itoa(value,string,radix);
    printf("changed words are %s.\n",string);
}
