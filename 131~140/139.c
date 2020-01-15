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
        fputs("Rep.Kor\n",fp);
        fclose(fp);
    }
}
