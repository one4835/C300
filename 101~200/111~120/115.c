#include<stdio.h>

void calc(int(*pjumsu)[3],int*ptotal);

void main(void)
{
    int jumsu[100][3];
    int total[3]={0,};
    int(*pjumsu)[3];

    pjumsu = jumsu;

    calc(pjumsu,total);

    printf("total of Korean %d\n",total[0]);
    printf("total of English %d\n",total[1]);
    printf("total of Math %d\n",total[2]);
}

    void calc(int(*pjumsu)[3],int*ptotal)
    {
        int i;

        for(i=0;i<100;i++)
        {
            pjumsu[i][0]=92;
            pjumsu[i][1]=90;
            pjumsu[i][2]=95;
        }

        for(i=0;i<100;i++)
        {
            ptotal[0] +=pjumsu[i][0];
            ptotal[1] +=pjumsu[i][1];
            ptotal[2] +=pjumsu[i][2];
        }

    }
