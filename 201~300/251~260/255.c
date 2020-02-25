#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;

    now = time(NULL);
    t = *localtime(&now);

    printf("This year's passed days : %d\n",t.tm_yday);
}
