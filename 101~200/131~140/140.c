#include <stdio.h>

void main(void)
{
    FILE*fp;
    char buffer[100];

    fp = fopen("c\\file.txt","w+");

    if(fp == NULL)
    {
        puts("we can't create file");
    }
    else
    {
        fgets(buffer,100,fp);
        puts(buffer);
        fclose(fp);
    }
}
