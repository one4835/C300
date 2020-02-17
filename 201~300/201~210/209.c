#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char string1[] ="1010";
    char string2[] ="ff";
    char *stop;
    long value;

    value = strtol(string1,&stop,2);
    printf("It's %d to change 2x\"%s\".\n",string1,value);

    value = strtol(string2,&stop,16);
    printf("It's %d to change 16x\"%s\".\n",string2,value);
}
