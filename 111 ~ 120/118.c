#include <stdio.h>
void clac(int(*pjumsu)[100][3],int*ptotal);

void main(void)
{

    int jumsu[10][100][3];
    int total[3]={0,};

    calc(jumsu,total);

    printf("total of every classroom's Korean: %d\n",total[0] );
    printf("total of every classroom's English: %d\n",total[1] );
    printf("total of every classroom's Math: %d\n",total[2] );


    for(i=0;i<10;i++)
    {
        for(j=0;j<100;j++)
        {
            pjumsu[i][j][0] = 92;
            pjumsu[i][j][1] = 90;
            pjumsu[i][j][2] = 95;
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<100;j++)
        {
            total[0]+=pjumsu[i][j][0];
            total[1]+=pjumsu[i][j][1];
            total[2]+=pjumsu[i][j][2];
        }
    }

}
