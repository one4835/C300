#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void)
{
    char *string =" 123 ";
    char buff[20] = {0,};
    int i = 0;

    printf("Length of 'string' : %d\n",strlen(string));

    while(*string)
    {
        if(!isspace(*string))
        {
            buff[i++] = *string;
        }
        string++;
    }
    puts(buff);
    printf("Length of 'string' : %d\n",strlen(buff));
}
