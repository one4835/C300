#include<stdio.h>
#include<string.h>

void main(void)
{
    char string[100];

    puts("Press Enter after entering sentense. ");
    puts("Entering nothing will exit the program ");

    do
    {
        gets(string);

        if(strlen(string)== 0)break;

        pstr = strdup(string);

        strcpy(string);
        printf(" words string :%s\n", );
        printf(" words pstr : %s\n", );

        free(pstr);

    }while(1);
}
