#include<stdio.h>
#include<string.h>

#define SKY "sky"

void main(void)
{
    char string[100];
    char *ret;

    puts("After entering the sentense, press enter.");
    puts("Sentense contains 'sky'will exit the program");

    do
    {
        gets(string);

        ret = strstr(string,SKY);

        if(ret == NULL)
        {
            puts("There is no 'sky' in the sentense");
        }
        else
        {
            printf("We found 'sky'on the locationof[%d]",ret - string);
            break;
        }

    } while(1);
}
