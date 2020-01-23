#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;

    time(&now);

    printf("date and time now:%s",ctime(&now));

}
