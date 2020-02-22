#include <stdio.h>

void main(void)
{
    FILE *fp;

    fp = fopen("c:\\file.txt","w+");

    if(fp != NULL)
    {
        fputs("Korea\n",fp);
        fputs("Korea\n",fp);
        fputs("Korea\n",fp);
        fputs("Korea\n",fp);
        fputs("Korea\n",fp);
        fclose(fp);
    }
}
