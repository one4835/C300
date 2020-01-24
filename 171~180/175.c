#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;

    now = time(NULL);
    t = *localtime(&now);

    printf("date and time: %s\n",asctime(&t));

}
