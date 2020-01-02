#include<stdio.h>
#include<string.h>

void main(void)
{
    char*string1 = "2 is bigger than 1.";
    char*string2 = "1004 is one thousand four";
    char*string3 = "it's 2020";
    char*string4 = "today is Jan.2nd";
    long t1, t2, t3, t4;

    puts(string1);
    puts(string2);
    puts(string3);
    puts(string4);

    t1 = atol(string1);
    t2 = atol(string2);
    t3 = atol(string3);
    t4 = atol(string4);

    printf("changed num of words: %ld, %ld, %ld, %ld\n",t1,t2,t3,t4);
    printf("total is %d\n",t1, t2, t3, t4);
}
