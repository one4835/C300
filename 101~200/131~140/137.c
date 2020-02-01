#include <stdio.h>

void main(void)
{
    FILE*fp;

    fp = fopen("c:\\file.txt","w+");

    if(fp ==NULL)
    {
        puts("We can't create file");
    }
    else
    {
        fputc('A',fp);
        puts("File had been created succesfully");
        fclose(fp);

    }
}
