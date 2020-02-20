#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = " .;;abc;;. ";
    char *sep = ".;";
    int nIndex1,nIndex2;

    nIndex1 = strspn(string,sep);
    nIndex2 = strcspn(&string[nIndex1],sep);
    (&string[nIndex1])[nIndex2] = 0;
    printf("%s\n",&string[nIndex1]);
}
