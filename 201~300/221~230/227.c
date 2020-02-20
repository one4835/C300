#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void)
{
    char buff[]= "boy is man",*pos = buff;

    while(pos){
        if(isalpha(buff[0])&& pos == buff){
            buff[0]&= 0xDF;
            pos++;
        }
        else if(pos = strpbrk(pos," "))*++pos &= 0xDF;
    }
    printf(buff);
}
