#include <stdio.h>
#include <direct.h>

void main(void)
{
    char *pathname ="c:\\ccc";

    if(_mkdir(pathname)== -1)
    {
        perror("Directory creating error");
    }
    else
    {
        puts("Creating directory successfully");
    }
}
