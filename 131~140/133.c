#include <stdio.h>
#include <string.h>

void main(void)
{
    int (*myfunc)(const char*);

    myfunc[0] = puts;
    myfunc[1] = strlen;
    myfunc[2] = myfunc[1];

    puts("123456");
    myfunc("7890");

    printf("length of string: %d\n",strlen("aa"));
    printf("length of string: %d\n", myfunc[1]("aa"));
    printf("length of string: %d\n", myfunc[2]("aa"));
}
