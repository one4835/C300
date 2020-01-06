#include <stdio.h>
#include <string.h>
#include <stdilb.h>
#include <malloc.h>

#define MEMORY "MEMORY"

void main(void)
{
    char*pmem;

    pmem = malloc(100);

    if(pmem == NULL)
    {
        puts("We can't pointer memory.");
    }
    else
    {
        strcpy(pmem,MEMORY);
        puts(pmem);

        free(pmem);
        
    }
}
