#include <stdio.h>

void main(void)
{
    FILE *fp;
    char buff[100];

    fp = fopen("c:\\file.txt","r");

    if(fp != NULL)
    {
        while(!feof(fp))
        {
            fgets(buff,100,fp);
            printf(buff);
        }
        fclose(fp);
    }
}
