#include <stdio.h>
#include <conio.h>

#define ENTER 13

void main(void)
{
    int ch;

    printf("Press the key that you want to change to ASCII cord...\n");
    printf("If you press Enter, program would end\n");

    do
    {
        ch = getch();

        printf("text :(%c), ASCII cord = (%d)\n",ch,ch);
        
    }while(ch != ENTER);
}
