#include<stdio.h>

void main(void)
{
    FILE *fp;
    fpos_t pos;

    fp = fopen("c:\\file.txt","w+");

    fgetpos(fp,&pos);
    fputs("abcde",fp);
    fsetpos(fp,&pos);
    printf("File pointer's point :%d\n",ftell(fp));
    fclose(fp);
}
