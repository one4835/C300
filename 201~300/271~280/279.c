#include <stdio.h>

#define SECRETKEY "!@#$%^&*()_+=-"

void main(void)
{
    int i;
    char string[] = "1234567890";

    puts(string);

    for(i=0;i<strlen(string);i++)
    {
        string[i]^=SECRETKEY[i];
    }

    puts(string);

    for(i=0;i<strlen(string);i++)
    {
        string[i]^=SECRETKEY[i];
    }

    puts(string);
}
