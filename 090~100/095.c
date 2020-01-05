#include <stdio.h>
#include <ctype.h>

void main (void)
{
    char string1[]= "1a2b3c4d5e";
    char string2[] = "..........";

    puts(string1);
    puts(string2);

    swab(string1,string2,sizeof(string1)-1);

    puts(string1);
    puts(string2);
}
