#include<stdio.h>
#include <string.h>

char s[20]="1234567890";

void*My_memmove(void *dst,const void*src,unsigned int count);

void main(void)
{
    puts(s);
    My_memmove(s+4,s+2,6);
    puts(s);
}

void*My_memmove(void*dst,const void*src,unsigned int count)
{
    void*ret = dst;

    if(dst<= src||(char*)dst>=((char*)src +count))
    {
        while(count--)
        {
            *(char*)dst =*(char*)src;
            dst = (char*)dst +1;
            src = (char*)src +1;
        }
    }
    else
    {
        dst = (char*)dst +count-1;
        src = (char*)src +count-1;

        while(count--)
        {
            *(char*)dst =*(char*)src;
            dst = (char*)dst -1;
            src = (char*)src -1;
        }
    }

    return ret;
}
