#include<stdio.h>
#include<stdilb.h>

void main(void)
{
    double value;
    char pstr;
    int dec,sign;

    value = 3.1415926535;
    pstr = fcvt(value,6,&dec,&sign);
    printf("changed words are %s.\n",pstr);

    value = -3.1415926535;
    pstr = fcvt(value,6,&dec,&sign);
    printf("changed words are %s.\n",pstr);
}
