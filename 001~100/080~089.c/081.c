#include<stdio.h>
#include<string.h>

void main(void)
{
    char*string1 = "2.1 is bigger than 1.0";
    char*string2 = "1004.5 is one thousand four.five";
    char*string3 = "it's 2020";
    char*string4 = "today is Jan.2nd";
    double t1, t2, t3, t4;

    puts(string1);
    puts(string2);
    puts(string3);
    puts(string4);

    t1 = atof(string1);
    t2 = atof(string2);
    t3 = atof(string3);
    t4 = atof(string4);

    printf("changed num of words: %lf, %lf, %lf, %lf\n",t1,t2,t3,t4);
    printf("total is %d\n",t1, t2, t3, t4);
}
