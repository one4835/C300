#include <stdio.h>
#include <string.h>

void main (void)
{
    char string[100];

    puts("Press Enter after entering sentense");
    puts("Putting nothing will exit the program");

    do
    {
        gets(string);

        if(strlen(string)==0)break;

        strupr(string);
        puts(string);

    }while(1);
}
