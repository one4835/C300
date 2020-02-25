#include <stdio.h>
#include <time.h>

void sleep(int sec);

void main(void)
{
    time_t n1,n2;

    time(&n1);
    sleep(10);
    time(&n2);

    printf("%g seconds delayed\n",difftime(n2,n1));
}

void sleep(int sec)
{
    clock_t ct;
    ct = clock();
    while(ct+CLK_TCK*sec>clock());
}
