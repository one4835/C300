#include <stdio.h>
#include <time.h>
#include <string.h>

void main(void)
{
    time_t now;
    struct tm t;
    char buff[100],AMPM[10];

    now = time(NULL);
    t = *localtime(&now);
    strftime(buff,sizeof(buff),"%Y-%m-%d %H:%M:%S",&t);

    strftime(AMPM,sizeof(AMPM),"%p",&t);
    if (strcmp(buff,"AM"))strcpy(AMPM,"A.M.");
    else if(strcmp(buff,"PM"))strcpy(AMPM,"P.M.");
    strcat(buff,AMPM);

    puts(buff);
}
