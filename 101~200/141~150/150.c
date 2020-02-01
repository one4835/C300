#include <stdio.h>

void main(void)
{
    FILE*fp;
    fpos_t pos;

    fp = fopen("c\\file.txt","w+");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        fputs("abcde",fp);
        fgetpos(fp, &pos);
        printf("file pointer's point : %d\n",pos);
        fclose(fp);
    }
}
