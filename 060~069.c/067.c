#include<stdio.h>
#include<string.h>

void main(void)
{
    char*string = "this is a very good!";
    char*strCharset = "abcdefghijklmnopqrstuvwxyz "
    unsigned int pos;

    pos = strspn(string,strCharset);

    puts("0     1       2       3");
    puts("0123456789012345678901234567890");
    puts(string);
    puts(strCharset);

    printf("We found the incorrect word on the location of[%d]",pos);
}
