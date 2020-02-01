#include <stdio.h>
#include <string.h>


void main(void)
{
    char s1[100] = "123";
    char s1[100] = "123";

    strcpy(&s1[4],"abc");
    strcpy(&s2[4],"efg");

    if(strcmp(s1,s2)==0)
    {
        puts("strcmp: buffer is equel");
    }

    if(memcmp(s1,s2,7)==0)
    {
        puts("memcmp: buffer is equel");
    }
    else
    {
        puts("memcmp:buffer is not equel");
    }
}
