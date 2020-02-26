#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
    char date[] = "2005-06-23";
    time_t now;
    struct tm t = {0,};

    t.tm_mday = atoi(&date[8]);
    t.tm_mon = atoi(&date[5])-1;
    t.tm_year = atoi(&date[0])-1900;

    now = mktime(&t);
    printf("Change 2005-06-23 into time_t is%d\n",now);
}
