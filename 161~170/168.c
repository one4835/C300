#include <stdio.h>
#include <direct.h>

void main(void)
{
    time_t now;

    time(&now);
    printf("second from 1970.1.1. ~ now %d\n",now);
}
