#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t s1,s2;
    double gop;
    int i;

    time(&s1);

    for(i - 0;i < 10000000;i++)
    {
        gop = gop *100;
    }

    time(&s2);

    printf("time :%g second\n",difftime(s2,s1));
}
