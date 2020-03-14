#include<stdio.h>

void main(void)
{
    int i;
    int jumsu[100][3];
    int total[3]={0,};

    for(i=0;i<100;i++)
    {
        jumsu[i][0]=92;
        jumsu[i][1]=90;
        jumsu[i][2]=95;
    }

    for(i=0;i<100;i++)
    {
        total[0] +=jumsu[i][0];
        total[1] +=jumsu[i][1];
        total[2] +=jumsu[i][2];
    }

    printf("total of Korean %d\n",total[0]);
    printf("total of English %d\n",total[1]);
    printf("total of Math %d\n",total[2]);
}
