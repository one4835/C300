#include<stdio.h>
#include<stdilb.h>

void main(void)
{
    long value;
    char string[100];
    int radix;

    radix = 2;

    value = 12345;
    ltoa(value,string,radix);
    printf("changed words are %s.\n",string);

    value = -12345;
    ltoa(value,string,radix);
    printf("changed words are %s.\n",string);
}
