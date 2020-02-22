#include <stdio.h>

void main(void)
{
    char *filename = "c:\\file.txt";
    char *movefile = "c:\\temt\\file.txt";

    if(rename(filename,movefile) != 0)
    {
        perror("File moving error");
    }
    else
    {
        puts("File had moved");
    }
}
