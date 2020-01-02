#include<stdio.h>
#include<string.h>

void main(void)
{
    char*string"11000";
    char*stop;
    int radix;
    unsigned long value;

    radix = 2;

    value = strtoul(sting,&stop,radix);

    printf("%d of the words are changed.\n",stop - string);
    printf("It's %u that %s changed into number\n",string,value);
}
