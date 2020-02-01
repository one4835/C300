#include <stdio.h>

void main(void)
{
    FILE*fp;
    int i;

    fp = fopen("c\\file.txt","w+");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        fscanf(fp,"%d",&i);
        printf("i = %d\n",i);
        fclose(fp);
    }
}
