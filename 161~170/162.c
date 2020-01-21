#include <stdio.h>
#include <direct.h>

void main(void)
{
    char *pathname ="c:\\ccc";

    if(_rmdir(pathname)== -1)
    {
        perror("Directory deleteing error");
    }
    else
    {
        puts("Deleteing directory successfully");
    }
}
