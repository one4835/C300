#include<stdio.h>
#include<string.h>

void main(void)
{
    int count;
    int total = 0;
    char string[100];

    for(count = 1;count<= 3; count++)
    {
        printf("Enter the %d th words and press enter.\n",count);

        gets(string);

        total += atoi(string);

        printf(" count = %d, total = %d\n",atoi(string),total);
    }

    printf("total is %d.\n",total);
}
