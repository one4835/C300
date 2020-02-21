#include <stdio.h>

void array_copy(void *dest,const void*src,int size);

void main(void)
{
    char array1[100] = "array of char";
    char array2[100] = {0,};
    int array3[5] = {1,2,3,4,5};
    int array4[5] = {0,};

    printf("array1:[%s]\n",array1);
    printf("array2:[%s]\n",array2);
    printf("array3:[%s]\n",array3[0]);
    printf("array4:[%d]\n",array4[0]);

    array_copy(array2,array1,sizeof(array1));
    array_copy(array4,array3,sizeof(array3));

    printf("array1:[%s]\n",array1);
    printf("array2:[%s]\n",array2);
    printf("array3:[%s]\n",array3[4]);
    printf("array4:[%d]\n",array4[4]);
}

void array_copy(void*dest,const void*src,int size)
{
    while(size--)
    {
        *(char*)dest = *(char*)src;
        ((char*)dest)++;
        ((char*)src)++;
    }
}
