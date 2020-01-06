#include <stdio.h>
#include <ctype.h>

void main (void)
{
    char*string = "This is Korea!\t\n";
    int cnt = 0;

    while(*string)
    {
        if(isspace(*string))
        {
            cnt++;
        }

        string++;
    }

    printf("space,tab,words number is %d",cnt)
}
