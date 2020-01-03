#include<stdio.h>
#include<stdilb.h>

void main(void)
{
    unsigned value;
    char string[100];
    int radix;

    radix = 16;

    value = 34567;
    ultoa(value,string,radix);
    printf("changed words are %s.\n",string);

    value = 1234567890;
    ultoa(value,string,radix);
    printf("changed words are %s.\n",string);
}
