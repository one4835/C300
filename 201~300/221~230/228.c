#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void)
{
    char buff[]="copy words";
    char *dup;

    dup = strdup(buff);
    if(dup)
    {
        strcpy(buff,"other words");
        puts(buff);
        puts(dup);
        free(dup);
    }
}
