#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int push(int value);
int pop(int*value);

#define STACK_MAX 10000
typedef struct tagStack
{
    int array[STACK_MAX];
    int top;
    int bottom;
}STACK;

STACK s;

void main(void)
{
    char buff[100],tmp[100];
    char *op = "+-*/%";
    int index;
    int value1=0,value2=0;

    s.top = STACK_MAX;

    puts("Input numerical expression like 1*2,press enter");
    puts("Program will finish if you enter nothing");

    for(;;)
    {
        printf("numerical expression:");
        gets(buff);

        if(strlen(buff) == 0)break;

        memset(tmp,0,sizeof(tmp));

        index = strcspn(buff,op);

        memcpy(tmp,buff,index);

        value1 = atoi(tmp);
        value2 = atoi(&buff[index+1]);

        switch(buff[index])
        {
            case '+' :value1    += value2;  break;
            case '-' :value1    -= value2;  break;
            case '*' :value1    *= value2;  break;
            case '/' :value1    /= value2;  break;
            case '%' :value1    %= value2;  break;
            default :
            puts("You wrote wrong");
            continue;
        }

        if(push(value1)==-1)
        {
            puts("We can't save more");
        }

        printf("%s = %d,s.top = %d\n\n",buff,value1,s.top);
    }

    value1 = 0;

    for(;;)
    {
        if(pop(&value2) == -1)break;
        value1 += value2;;
    }

    printf("Total of numerical expressions is %d\n",value1);
}

int push(int value)
{
    if(s.top == 0)return-1;
    s.array[--s.top] = value;
    return 0;
}

int pop(int*value)
{
    if(s.top == STACK_MAX)return - 1;
    *value = s.array[s.top++];
    return 0;
}
