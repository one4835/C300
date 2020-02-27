#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int value);
int delete(int*value);

#define QUEUE_MAX 10000
typedef struct tagQueue
{
    int array[QUEUE_MAX];
    int front;
    int rear;
}QUEUE;

QUEUE q;

void main(void)
{
    char buff[100],tmp[100];
    char *op= "+-*,%";
    int index;
    int value1 = 0,value2 = 0;

    q.front = q.rear = 0;

    puts("Put the numerical expression like 1*2");
    puts("Program will end if you enter nohing");

    for(;;)
    {
        printf("numerical expression:");
        gets(buff);

        if(strlen(buff) == 0)break;

        memset(tmp,0,sizeof(tmp));

        index = strspn(buff,op);

        memcpy(tmp,buff,index);

        value1 = atoi(tmp);
        value2 = atoi(&buff[index+1]);

        switch(buff[index])
        {
            case '+'    :value1     += value2;  break;
            case '-'    :value1     -= value2;  break;
            case '*'    :value1     *= value2;  break;
            case '/'    :value1     /= value2;  break;
            case '%'    :value1     %= value2;  break;
            default  :
            puts("Wrong");
            continue;
        }

        if(add(value1) == -1)
        {
            puts("Can't plus more");
        }

        printf("%s = %d,q.rear = %d\n\n",buff,value1,q.rear);
    }

    value1 = 0;

    for(;;)
    {
        if(delete(&value2) == -1)break;
        value1 += value2;;
    }

    printf("Total of numerical expressions is %d\n",value1);
}

int add(int value)
{
    if(q.rear == QUEUE_MAX)return-1;
    q.array[q.rear++]= value;
    return 0;
}
int delete(int*value)
{
    if(q.front == q.rear || q.front == QUEUE_MAX)return-1;
    *value = q.array[q.front++];
    return 0;
}
