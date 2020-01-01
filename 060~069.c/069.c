#include <stdio.h>
#include <string.h>

#define TOKEN " "

void main (void)
{
    char string[100];
    char*pos;

    puts("Press Enter after entering sentense.");

    gets(string);

    pos = strbrk(string,TOKEN);

    while(pos != NULL)
    {
        puts(pos++);

        pos = strbrk(pos,TOKEN);
    }
}
