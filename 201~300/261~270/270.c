#include <stdio.h>

#define ADDRFILE

typedef struct tagLinkeList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkeList*prev;
    struct tagLinkeList*next;
}ADDR;

void main(void)
{
    ADDR*addr;
    FILE*fp;

    fp = fopen(ADDRFILE,"rb");

    if(fp == NULL)
    {
        perror("File opening error");
        return;
    }

    while(!feof(fp))
    {
        fread(&addr,1,sizeof(ADDR),fp);

        if(ferror(fp))break;

        printf("name:%s\n",addr.name);
        printf("pone number:%s\n",addr.tel);
        printf("address:%s\n",addr.addr);
    }
}
