#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now,n1,n2;
    struct tm t1,t2;

    time(&now);
    t1=*localtime(&now);
    t2=*gmtime(&now);

    n1=mktime(&t1);
    n2=mktime(&t2);

    printf("Difference of Korea localtime and world time : %g hour\n",difftime(n1,n2)/3600.);;
}
