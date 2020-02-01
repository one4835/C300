#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[50] = "my beautiful country,Korea.";

    puts(string);

    memset(string,(int)NULL,sizeof(string));

    memset(string,'*',sizeof(string)-1);
    puts(string);
}
