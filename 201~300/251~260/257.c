#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;
    char buff[100];

    now = time(NULL);
    t = *localtime(&now);
    strftime(buff,sizeof(buff),"weekday : %A",&t);
    puts(buff);
    strftime(buff,sizeof(buff),"weekday : %a",&t);
    puts(buff);
    printf("%d\n",t.tm_wday);
}
