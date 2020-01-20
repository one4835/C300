#include<stdio.h>

void main(void)
{
    char *oldname = "c:\\file.txt";
    char *newname = "c:\\file_1.txt";

    if(rename(oldname, newname)!=0)
    {
        perror("File name change error");
    }
    else
    {
        puts("Changing file name succeed");
    }
}
