#include<stdio.h>
#include<string.h>

#define TOKEN ""

void main(void)
{
    char string[100];
    char*token;

    puts("Press Enter after entering sentense");

    gets(string);

    token = strtok(string, TOKEN);

    while(token != NULL)
    {
        puts(token);

        token = strtok(NULL,TOKEN);
    }
}
