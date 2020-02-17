#include <stdio.h>

void main(void)
{
    int i,hap=0;

    for(i=0;i<=100;i++)
    {
        if(i%2)
        {
            hap += i;
        }
    }

    printf("total of odd nums 1 to 100 :%d\n",hap);
}
