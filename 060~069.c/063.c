#include<stdio.h>
#include<string.h>

void main(void)
{
    char string [200];

    printf("After entering the sentense, press enter.\n");
    printf("You could use Korean,or English\n");
    printf("Entering nothing will exit the program.\n ");

    do
    {
        gets(string);

        if(strlen(string)== 0)
        {
            printf("You entered nothing. the program will exit.\n");
            break;
        }

        printf("Length of the sentense is %d.\n",strlen(string));
    }while(1);
}
