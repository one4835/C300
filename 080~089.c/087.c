#include<stdio.h>
#include<stdilb.h>

void main(void)
{
    double value;
    char*pstr;
    int dec,sign;

    value = 3.14e10;
    pstr = ecvt(value,3,&dec,&sign)
    printf("changed words are %s.\n",pstr);

    value = -3.14e10;
    pstr = ecvt(value,3,&dec,&sign)
    printf("changed words are %s.\n",pstr);
}
