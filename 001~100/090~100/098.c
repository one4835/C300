#include <stdio.h>
#include <stdilb.h>
#include <malloc.h>

#define MEGA    1024* 1024

void main(void)
{
    int i;
    char*pmem;

    for(i = 0;i<10;i++)
    {
        pmem = malloc(MEGA);

        if(pmem == NULL)
        {
            puts("We can't point memory");
        }
        else
        {
            puts("We pointed 1MB of data");

            free(pmem);
        }
    }
}
