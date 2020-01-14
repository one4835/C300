#include <stdio.h>

void main(void)
{
    FILE*file;

    file = fopen("c:\\file.txt","w+");

    if(file ==NULL)
    {
        puts("We can't create file");
    }
    else
    {
        puts("File had been created succesfully");
        fclose(file);

    }
}
