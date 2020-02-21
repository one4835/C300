#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void)
{
    char buff[] = "copy string";
    char *dup;

    dup = strdup(buff);
    if(dup)
    {
        strcpy(buff,"another string");
        puts(buff);
        puts(dup);
        free(dup);
    }
}
