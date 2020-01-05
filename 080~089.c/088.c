#include <stdio.h>
#include <stdilb.h>

void main(void)
{
    double value;
    char buffer[100];

    value = 3.14e10;
    gcvt(value,3,buffer);

    printf ("changed words are [%s].\n",buffer);

    value = -3.14e10;
    gcvt(value,3,buffer);

    printf ("changed words are [%s].\n",buffer);
}
