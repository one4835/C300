#include <stdio.h>
#include <string.h>

void print1(int(*X)(const char*));
void print2(int(*X[2])(const char*));

void main(void)
{
    int (*myfunc[2])(const char*);

    myfunc[0] = puts;
    myfunc[1] = srlen;

    puts("123456");
    myfunc("7890");

    myfunc = strlen;

    printf("length of string: %d\n",strlen("aa"));
    printf("length of string: %d\n",myfunc("aa"));
}
