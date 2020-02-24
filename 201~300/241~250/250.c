#include <stdio.h>
#include <time.h>

void main(void)
{
    struct tm christmas = {0,0,0,25,12-1,2020-1900};
    char *wday[] = {"Sun","Mon","Tues","Wednes","Thurs","Fri","Satur"};
    char buff[100];

    mktime(&christmas);
    strftime(buff,sizeof(buff),"2020.12.25 is %A",
    &christmas);

    puts(buff);
    printf("2020.12.25 is %sday\n",wday[christmas.tm_wday]);
}
