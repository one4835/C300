#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char buff[100];
    int radix = 16;

    itoa(10,buff,radix);
    puts(buff);

    itoa(255,buff,radix);
    puts(buff);
}
