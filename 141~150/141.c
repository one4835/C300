#include <stdio.h>

void main(void)
{
    FILE*fp;
    int i =12345;

    fp = fopen("c\\file.txt","w+");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        fprintf(fp,"%d",i );
        fclose(fp);
    }
}
