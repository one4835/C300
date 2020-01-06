#include<stdio.h>
#include<string.h>

#define FIND_CHAR

void main(void)
{
    char string[100];
    char *ret;

    puts("After entering the sentense, press enter.");
    puts("Sentense contains 'h'will exit the program");

    do
    {
        gets(string);

        ret = strchr(string,FIND_CHAR);

        if(ret != NULL)
        {
            puts("There is no 'h' in the sentense");
        }
        else
        {
            printf("We found 'h'on the locationof[%d]",ret - string);
            break;
        }

    } while(1);
}
