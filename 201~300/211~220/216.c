#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = "a12,b34,c56";
    char *token;

    token = strtok(string,",");

    while(token)
    {
        puts(token);
        token = strtok(NULL,",");
    }
}
