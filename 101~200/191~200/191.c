#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int intcmp(const void*v1,const void* v2);

void main(void)
{
    int key = 5,*ptr;
    int array[10] = {150,27,33,1,5,100,99,75,81,10};

    qsort(array,10,sizeof(array[0]),intcmp);
    ptr = bsearch(&key,array,10,sizeof(array[0]),intcmp);

    if(ptr)
    {
        puts("we found 5.");
    }
}

int intcmp(const void*v1,const void* v2)
{
    return(*(int*)v1 -*(int*)v2);
}
