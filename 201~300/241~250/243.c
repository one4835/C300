#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void main(void)
{
    FILE *fpR,*fpW;
    char buff[200];
    char *pbuf,*dup;
    int len,pos1,pos2;

    fpR = fopen("c:\\file.txt","r");

    if(fpR == NULL)
    {
        perror("File reading open error");
        return;
    }
    fpW = fopen("c:\\file_change.txt","w+");

    if(fpW == NULL)
    {
        perror("File writing open error");
        _fcloseall();
        return;
    }

    while(!feof(fpR))
    {
        fgets(buff,200,fpR);

        pbuf = strstr(buff,"Korea");

        if(pbuf)
        {
            len = strlen(buff);
            pos1 = pbuf - buff;

            dup = strdup(buff);
            strnset(&buff[pos1],0,len - pos1);
            strcat(buff,"Korea");

            pos1 = pbuf - buff + strlen("Korea");
            pos2 = pbuf - buff + strlen("Korea");

            strcpy(&buff[pos2],&dup[pos1]);
            free(dup);
        }

        if(!feof(fpR))fputs(buff,fpW);
    }

    _fcloseall();
    puts("We changed Korea");
}
