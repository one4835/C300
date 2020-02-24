#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t,christmas = {0,0,0,25,12,2005};
    int n1,n2,nChristmas;

    now = time(NULL);
    t=*localtime(&now);

    christmas.tm_year-=1900;
    christmas.tm_mon-=1;

    n1 = mktime(&t);
    n2 = mktime(&christmas);

    nChristmas = (n2-n1);
    christmas = *localtime(&nChristmas);

    printf("Todat's date is %s",ctime(&now));
    printf("Days left for christmas is%dmonthes %ddays %dhour %dminutes %dseconds\n",
        christmas.tm_mon,christmas.tm_mday,
        christmas.tm_hour,christmas.tm_min,christmas.tm_sec);
}
