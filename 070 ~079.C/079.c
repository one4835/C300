#include<stdio.h>
#include<string.h>

void main(void)
{
    char*string = "0xFF";
    char*stop;
    int radix;
    long value;

    radix = 16;

    value = strtol(string,&stop,radix);

        printf("%d of the words are changed.\n",stop - string);
        printf("It's %ld that %s changed into number\n",string,value);
}
