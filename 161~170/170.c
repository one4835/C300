#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

void main(void)
{
    struct _timeb tb;
    struct tm t;

    _ftime(&tb);

    t =*localtime(&tb.time);

    printf("date and time now- date: %4d.%d.%d time:%d:%d:%d\n",
    t.tm_year +1900, t.tm_mon +1,t.tm_mday,
    t.tm_hour, t.tm_min, t.tm_sec);
}
