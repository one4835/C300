#include <stdio.h>

void main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("c:\\file.txt","r");

    if(fp == NULL)
    {
        puts("File opening error");
    }
    else
    {
        while(!feof(fp))
        {
            ch = fgetc(fp);
            if(ferror(fp))
            {
                puts("File reading error");
            }
        }
        fclose(fp);
    }
}
