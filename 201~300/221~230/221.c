#include <stdio.h>
#include <string.h>

void main(void)
{
    char *string = "i t's good";
    char *find = "abcdefghijklmnopqrstuvwxyz";
    int nIndex;

    nIndex = strspn(string,find);
    printf("We found the first word that isn't alphabet at %d\n",nIndex);
}
