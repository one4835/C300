#include <stdio.h>
#include <string.h>

void main(void)
{
    int (*myfunc)(const char*);

    myfunc = puts;

    puts("123456");
    myfunc("7890");

    myfunc = strlen;

    printf("length of string: %d\n",strlen("aa"));
    printf("length of string: %d\n",myfunc("aa"));
}
