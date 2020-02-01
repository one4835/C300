#include <stdio.h>

void main(void)
{
    FILE*fp;

    fp = fopen("c\\file.txt","w+");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        printf("file pointer's point : %d\n",ftell(fp));
        fputs("abcde",fp);
        printf("file pointer's point : %d\n",ftell(fp));
        rewind(fp);
        printf("file pointer's point : %d\n",ftell(fp));
        fseek(fp,0L,SEEK_END);
        printf("file pointer's point : %d\n",ftell(fp));
        fclose(fp);
    }
}
