#include <stdio.h>

void main(void)
{
    FILE*fp;

    fp = fopen("c:\\file.txt","r");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        fseek(fp,0L,SEEK_END);
        printf("file pointer's point : %d\n",ftell(fp));
        fclose(fp);
    }
}
