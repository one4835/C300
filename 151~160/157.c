#include <stdio.h>
#include <io.h>

void main(void)
{
    char *path = "c:\\file.txt";

    if(_access(path, 0)== 0)
    {
        puts("File exists");
    }
}
