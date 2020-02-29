#include <stdio.h>      //printf,putd,fopen,fwrite,fclose
#include <malloc.h>     //malloc,free
#include <string.h>     //strcpy,strstr

#define ADDRFILE    "c:\\addrlist.txt"

typedef struct tagLinkeList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkeList*prev;
    struct tagLinkeList*next;
}ADDR;

ADDR*g_pAddrHead = NULL;


void get_addrlist(void);
int add_list(const ADDR*addr);
int find_list(const char*name);
void print_list(void);
void remove_list(void);
void SetHeadPosition(void);

void main(void)
{
    char name[30];

    get_addrlist();

    puts("Enter the name to search");

    while(1)
    {
        printf("Name:");
        gets(name);
        if(strlen(name)==0)break;
        find_list(name);
    }

    remove_list();
}

void get_addrlist(void)
{
    ADDR addr;
    FILE*fp;

    fp = fopen(ADDRFILE,"rb");

    if(fp == NULL)
    {
        perror("File opening error");
        return;
    }

    while(!feof(fp))
    {
        fread(&addr,sizeof(ADDR),1,fp);

        if(ferror(fp))
        {
            fclose(fp);
            perror("File reading error");
            return;
        }

        if(feof(fp))break;
        if(add_list(&addr)==0)
        {
            printf("Can't plus the address data.\n");
        }
    }

    fclose(fp);
}

int add_list(const ADDR*addr)
{
    ADDR *plocal;

    //g_pAddrHead가 초기화되지 않은 경우 한번만 실행시킵니다
    if(g_pAddrHead == NULL)
    {
        g_pAddrHead = malloc(sizeof(ADDR));

        if(g_pAddrHead == NULL)
        {
            return 0;
        }

        g_pAddrHead->prev = NULL;
        g_pAddrHead->next = NULL;
    }
    else
    {
        plocal = malloc(sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        g_pAddrHead->next = plocal;
        plocal->prev = g_pAddrHead;
        g_pAddrHead = plocal;
        g_pAddrHead->next = NULL;
    }

    strcpy(g_pAddrHead->name,addr->name);
    strcpy(g_pAddrHead->tel,addr->tel);
    strcpy(g_pAddrHead->addr,addr->addr);

    return 1;
}

int find_list(const char*name)
{
    ADDR *plocal;

    SetHeadPosition();

    plocal = g_pAddrHead;

    while(plocal)
    {
        if(strstr(plocal->name,name))
        {
            puts(plocal->name);
            puts(plocal->tel);
            printf("%s\n\n",plocal->addr);
            return 1;
        }
        plocal = plocal->next;
    }

    printf("\nCan't find%s\n\n",name);

    return 0;
}

void SetHeadPosition(void)
{
    if(g_pAddrHead == NULL)return;

    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }
}

void remove_list(void)
{
    ADDR*plocal;

    if(g_pAddrHead == NULL)return;

    //PA를 리스트의 맨 처음으로 이동
    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }

    //한 개씩 메모리 해제
    while(g_pAddrHead)
    {
        plocal =g_pAddrHead->next;

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }

    g_pAddrHead = NULL;
}
