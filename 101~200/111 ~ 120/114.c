#include<stdio.h>

void main(void)
{
    int i;
    int jumsu[100][3];
    int total[3]={0,};
    int(*pjumsu)[3];

    pjumsu = jumsu;

    for(i=0;i<100;i++)
    {
        pjumsu[i][0]=92;
        pjumsu[i][1]=90;
        pjumsu[i][2]=95;
    }

    for(i=0;i<100;i++)
    {
        total[0] +=pjumsu[i][0];
        total[1] +=pjumsu[i][1];
        total[2] +=pjumsu[i][2];
    }

    printf("total of Korean %d\n",total[0]);
    printf("total of English %d\n",total[1]);
    printf("total of Math %d\n",total[2]);
}
