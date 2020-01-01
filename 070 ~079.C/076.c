#include<stdio.h>
#include<string.h>

void main(void)
{
    char cValue = 'a';
    int iValue = 1234567;
    long lValue = 7890123;
    float fValue = 3.141592;
    double dValue = 3.141592;
    char*string = "korea";
    char buffer[100];

    sprintf(buffer,"char is %c",cValue);
    puts(buffer);

    sprintf(buffer,"int is %d",iValue);
    puts(buffer);

    sprintf(buffer,"long is %ld",lValue);
    puts(buffer);

    sprintf(buffer,"float is %f",fValue);
    puts(buffer);

    sprintf(buffer,"double is %e",dValue);
    puts(buffer);

    sprintf(buffer,"char* is %s",string);
    puts(buffer);
}
