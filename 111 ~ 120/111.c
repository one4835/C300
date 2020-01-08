#include <stdio.h>
#include <string.h>

void main(void)
{
    char one[] = "Korea";
    char*pone;

    pone = one;

    puts(one);
    puts(pone);

    strcpy(pone,"Japan");

    puts(one);
    puts(pone);
}
