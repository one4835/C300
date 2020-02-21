#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MEGA_BYTE 1048576

void main(void)
{
    char *pbuf;

    pbuf = malloc(100 * MEGA_BYTE);

    if(pbuf)
    {
        memset(pbuf,0,100 * MEGA_BYTE);

        strcpy(&pbuf[0],"Mokdong,Seoul");
        puts(&pbuf[0]);

        strcpy(&pbuf[1048576],"Kangseo,Busan");
        puts(&pbuf[1048576]);

        free(pbuf);
    }
}
