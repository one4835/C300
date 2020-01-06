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
            printf("We pointed %d byte of data\n",_msize(pmem));

            pmem = realloc(pmem,200);

            if(pmem == NULL)
            {
                puts("We can't repoint data");
            }
            else
            {
                printf("Repointed data is %d byte.\n",_msize(pmem));
            }

            free(pmem);
        }
    }
}
