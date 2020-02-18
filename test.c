#include <stdio.h>
#include <conio.h>

#define ENTER 13

void main(void)
{
    int ch;

    printf("Press the key to convert to ASCII code...\n");
    printf("Press ENTER to end the program.\n");

    do
    {
        ch = getch();

        printf("text : (%c), ASCII cord = (%d)\n",ch,ch);

    } while(ch != ENTER);
}
