#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void check_game(int saram,int computer);

enum{GAWI=1,BAWI,BO};
enum{WIN=1,LOSE,TIE};

int point = 15000;

void main(void)
{
    int gamer,computer,cheat=0;
    int COM_gawi_bawi_bo[3]={0,};
    int SRM_gawi_bawi_bo[3]={0,};

    srand(time(NULL));

    puts("Start rock-scissor-paper game.");
    puts("Press the number and press enter!!");

    for(;;)
    {
        printf("computer used %dtimes of scissors,%dtimes of rocks and %dtimes of paper\n"
        ,COM_gawi_bawi_bo[0],COM_gawi_bawi_bo[1],COM_gawi_bawi_bo[2]);

        printf("player used %dtimes of scissors,%dtimes of rocks and %dtimes of paper\n\n"
        ,SRM_gawi_bawi_bo[0],SRM_gawi_bawi_bo[1],SRM_gawi_bawi_bo[2]);

        computer = rand()%3+1;
        if(cheat)printf("computer use %s\n",
        computer==1?"scissor" :computer==2?"rock":"paper");

        printf("Now's money:%d won\nscissor(1) rock(2) paper(3) finish(4)-->point");

        scanf("%d",&gamer);

        if(gamer==4)
        {
            puts("Game over");
            return;
        }

        if(gamer==9)
        {
            puts("Use the cheetkey");
            cheat = 1;
        }

        if(gamer<0|| gamer>4)
        {
            puts("Press the number 1 to 4");
            continue;
        }

        COM_gawi_bawi_bo[computer-1]++;
        SRM_gawi_bawi_bo[gamer-1]++;

        check_game(gamer,computer);
    }
}

void check_game(int gamer,int computer)
{
    int flag;
    static int count_win = 0,count_lose = 0;

    switch (gamer)
    {
        case GAWI:
        flag = computer == BO? WIN :computer == BAWI? LOSE:TIE;
        break;

        case BAWI:
        flag = computer == GAWI? WIN :computer == BO? LOSE:TIE;
        break;

        case BO:
        flag = computer == BAWI? WIN :computer == GAWI? LOSE:TIE;
        break;
    }

    if(flag == WIN)
    {
        puts("\n You've won: +5000won\n");
        point += 5000;
        if(++count_win == 3)
        {
            puts("You've won for three times: bonus +10000won");
            point += 10000;
        }
        else if(count_win>= 5)
        {
            puts("You've won for more than five times.:bonus +30000won");
            point += 30000;
        }
        count_lose = 0;
    }
    else if(flag == WIN)
    {
        puts("\n You've lost: -5000won\n");
        point -= 5000;
        if(++count_lose == 3)
        {
            puts("You've won for three times: bonus -10000won");
            point -= 10000;
        }
        else if(count_lose>= 5)
        {
            puts("You've won for more than five times.:bonus -30000won");
            point -= 30000;
        }
        count_win = 0;
    }
    else
    {
        puts("\n Tied. One more time. Try again!");
    }


}
