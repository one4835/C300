#include <stdio.h>
#include <string.h>

void main(void)
{
    char buff[] = "password is 'Korea'";

    puts(buff);
    strset(buff,0);
    printf("[%s]\n",buff);
}
