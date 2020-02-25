#include <stdio.h>
#include <time.h>

void main(void)
{
    struct tm t1,t2;
    int n1,n2,n3;

    t1.tm_year = 2005-1900;
    t1.tm_mon = 6-1;
    t1.tm_mday = 15;
    t1.tm_hour = 1;
    t1.tm_min = 12;
    t1.tm_sec = 50;

    t2.tm_year = 2005-1900;
    t2.tm_mon = 6-1;
    t2.tm_mday = 15;
    t2.tm_hour = 3;
    t2.tm_min = 35;
    t2.tm_sec = 22;

    n1 = mktime(&t1);
    n2 = mktime(&t2);

    n3 = n2-n1;

    printf("Time 1:%4d-%02d-%02d %02d:%02d:%02d\n",
        t1.tm_year+1900,t1.tm_mon+1,t1.tm_mday,
        t1.tm_hour,t1.tm_min,t1.tm_sec);

        printf("Time 2:%4d-%02d-%02d %02d:%02d:%02d\n",
            t2.tm_year+1900,t2.tm_mon+1,t2.tm_mday,
            t2.tm_hour,t2.tm_min,t2.tm_sec);

            printf("Time difference: %d:%d:%d\n",
                n3/3600,(n3-((n3/3600)*3600))/60,n3%60);

}
