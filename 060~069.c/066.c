#include<stdio.h>
#include<string.h>

void main(void)
{
    char *string  = "This is a string$$$";
    char *strCharSet = "~!@#$%^&*()_+-={[}:;'<>./?]";
    unsigned int pos;

    pos = strcspn(string,strCharset);

    puts("0   1   2   3");
    puts("0123456789012345678901234567890");
    puts(string);
    puts(strCharSet);

    printf("We found same first letter on the location of[%d].\n",pos);
}
