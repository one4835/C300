#include<stdio.h>
#include <io.h>
#include <sys/stat.h>

void main(void)
{
    char *filename = "c:\\file_1.txt";

    if(_chmod(filename,_S_IREAD)!=0)
    {
        perror("File type change error");
    }
    else
    {
        puts("Changing file name succeed");
    }
}
