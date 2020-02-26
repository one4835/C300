#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
    char date[]= "2005-06-23 02:09:21";
    struct tm t = {0,};

    t.tm_sec    = atoi(&date[17]);
    t.tm_min    = atoi(&date[14]);
    t.tm_hour   = atoi(&date[11]);
    t.tm_mday   = atoi(&date[8]);
    t.tm_mon    = atoi(&date[5])-1;
    t.tm_year   = atoi(&date[0])-1900;

    mktime(&t);
    printf("After struct tm change date:%4d-%02d-%02d %02d:%02d:%02d\n",
        t.tm_year+1900,t.tm_mon+1,t.tm_mday,
        t.tm_hour,t.tm_min,t.tm_sec);
}
