#include <stdio.h>

void main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("c:\\file.txt","r");

    if(fp == NULL)
    {
        puts("We can't create file");
    }
    else
    {
        while(!feof(fp))
        {
            ch = fgetc(fp);
            printf("read word : %c\n",ch);
        }
    }
}
