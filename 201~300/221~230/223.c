#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = "a.book";
    char *pstr = string,*pfind = string;
    int i = 0;

    while(pfind)
    {
        pfind = strchr(pstr,'a');

        if(pfind == NULL)
        {
            pfind = strchr(pstr,'.');
            if(pfind) pstr = &string[++i];
        }
        else pstr = &string[++i];
    }
    puts(pstr);
}
