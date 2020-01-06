#include<stdio.h>
#include<string.h>

void main(void)
{
    char string1[100];
    char string2[100];

    printf("Enter the first word!\n");
    gets(string1);

    printf("Enter the second word!\n");
    gets(string2);

    strcat(string1,string2);

    puts(string1);
}
