#include <stdio.h>

void main(void)
{
    FILE *fp;
    char *string = "Our lake and mountains\n";

    fp = fopen("c:\\file.txt","w+");

    if(fp != NULL)
    {
        fwrite(string,1,strlen(string),fp);
        fwrite(string,1,strlen(string),fp);
        fwrite(string,1,strlen(string),fp);
        fclose(fp);
    }
}
