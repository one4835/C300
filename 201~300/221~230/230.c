#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void)
{
    char *pbuf;

    pbuf = malloc(100*10000);

    if(pbuf)
    {
        memset(pbuf,0,100*10000);
        strcpy(&pbuf[0],"Mokdong,Seoul");
        puts(&pbuf[0]);
        free(pbuf);
    }
}
