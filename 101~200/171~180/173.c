#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;

    time(&now);
    t = *localtime(&now);
    t.tm_mday += 100;
    mktime(&t);

    printf("date and time 100days later- date: %4d.%d.%d time:%d:%d:%d\n",
    t.tm_year +1900, t.tm_mon +1,t.tm_mday,
    t.tm_hour, t.tm_min, t.tm_sec);
}
