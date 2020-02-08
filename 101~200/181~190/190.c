#include <stdio.h>
#include <stdlib.h>

int intcmp(const void*v1,const void*v2);

void main(void)
{
    int i;
    int array[5] = {5,3,1,2,4};

    qsort(array,5,sizeof(array[0]),intcmp);

    for(i=0;i<5;i++)
    {
        printf("%d",array[1]);
    }
}

int intcmp(const void*v1,const void*v2)
{
    int cmpvalue1,cmpvalue2;

    cmpvalue1 =*(int*)v1;
    cmpvalue2 =*(int*)v2;

    return cmpvalue1 -cmpvalue2;
}
