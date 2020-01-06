#include <stdio.h>
#include <stdilb.h>
#include <malloc.h>

void main(void)
{
    char*pmem;

    printf("sizeof(int)'s length is %d'\n",sizeof(int));

    pmem = calloc(100,sizeof(int));

    if(pmem == NULL)
    {
        puts ("We can'tpoint memory");
    }
    else
    {
        puts("buffer that will save 100 of num is pointed");

        free(pmem);
    }
}
