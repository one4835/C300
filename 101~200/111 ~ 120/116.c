#include <stdio.h>

void main(void)
{
    int i,j;
    int jumsu[10][100][3];
    int total[3]={0,};

    for(i=0;i<10;i++)
    {
        for(j=0;j<100;j++)
        {
            jumsu[i][j][0] = 92;
            jumsu[i][j][1] = 90;
            jumsu[i][j][2] = 95;
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<100;j++)
        {
            total[0]+=jumsu[i][j][0];
            total[1]+=jumsu[i][j][1];
            total[2]+=jumsu[i][j][2];
        }
    }

    printf("total of every classroom's Korean: %d\n",total[0] );
    printf("total of every classroom's English: %d\n",total[1] );
    printf("total of every classroom's Math: %d\n",total[2] );
}
