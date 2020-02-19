#include <stdio.h>

void main(void)
{
    unsigned char *string = "대한민국 KOREA";
    unsigned char buff[20] = {0,};
    int i = 0;

    while(*string)
    {
        if (*string>127)
        {
            buff[i++] = *string;
        }
        string++;
    }
    puts(buff);
}
