#include<stdio.h>

void main(void)
{
    char *filename = "c:\\file_1.txt";

    if(remove(filename))
    {
        perror("File removing error");
    }
    else
    {
        puts("Removing file succeed");
    }
}
