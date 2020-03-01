#include <stdio.h>      //printf,puts,fopen,fwrite,fclose,getchar
#include <malloc.h>     //malloc,free
#include <string.h>     //strcpy,strstr

#define ADDRFILE        "c:\\addrlist.txt"

typedef struct tagLinkeList     //[exe-119]
{
    char name[30];              //name
    char tel[30];               //phone number
    char addr[100];             //address

    struct tagLinkeList *prev;
    struct tagLinkeList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;
ADDR *g_pFind;

void get_addrlist(void);
int add_list(const ADDR *addr);
int find_list(const char *name);
void print_list(void);
void remove_list(void);
void SetHeadPosition(void);

void main(void)
{
    char name[30],addr[100];
    int ch;

    get_addrlist();

    puts("Enter name to search");

    while(1)
    {
        printf("name:");
        gets(name);
        if(strlen(name) == 0)break;
        if(find_list(name) == 1)
        {
            printf("Would you change the address of %s(y/n)?",name);
            ch = getchar();
            fflush(stdin);
            if(ch =='Y'|| ch =='y')
            {
                puts("Put address for changing");
                printf("address:");
                gets(addr);
                strcpy(g_pFind->addr,addr);
            }
        }
    }

    remove_list();
}

void get_addrlist(void)
{
    ADDR addr;
    FILE *fp;

    fp = fopen(ADDRFILE,"rb");

    if(fp == NULL)
    {
        perror("File opening error");
        return;
    }

    while(!feof(fp))
    {
        fread(&addr,sizeof(ADDR),1,fp);

        if(ferror(fp));
        {
            fclose(fp);
            perror("File reading error");
            return;
        }

        if(!feof(fp))break;

        if(add_list(&addr) == 0)
        {
            printf("Can't plus address data to Linked List.\n");
        }
    }

    fclose(fp);
}

int add_list(const ADDR*addr)
{
    ADDR*plocal;

    //g_pAddrHead가 초기화되지 않은 경우,한 번만 실행됩니다.
    if(g_pAddrHead == NULL)
    {
        g_pAddrHead = malloc(sizeof(ADDR));

        if(g_pAddrHead == NULL)
        {
            return 0;
        }

        g_pAddrHead->prev = NULL;       //처음에는 반드시 NULL로 초기화
        g_pAddrHead->next = NULL;       //처음에는 반드시 NULL로 초기화
    }
    else//g_pAddrHead가초기화된 후 계속 실행합니다
    {
        plocal = malloc(sizeof(ADDR));  //ADDR구조체 할당

        if(plocal == NULL)
        {
            return 0;
        }

        g_pAddrHead->next = plocal;     //다음 리스트를 지정
        plocal->prev = g_pAddrHead;     //이전 리스트를 지정
        g_pAddrHead = plocal;           //현재 리스트로 plocal을 지정
        g_pAddrHead->next = NULL;       //다음 리스트를 NULL로 지정
    }

    strcpy(g_pAddrHead->name,addr->name);
    strcpy(g_pAddrHead->tel,addr->tel);
    strcpy(g_pAddrHead->addr,addr->addr);

    return 1;
}

int find_list(const char*name)
{
    ADDR*plocal;

    SetHeadPosition();

    plocal = g_pAddrHead;

    while(plocal)
    {
        if(strstr(plocal->name,name))
        {
            puts(plocal->name);
            puts(plocal->tel);
            printf("%s\n\n",plocal->addr);
            g_pFind = plocal;
            return 1;
        }
        plocal = plocal->next;
    }

    printf("\nCan't find %s\n\n",name);

    return 0;
}

void SetHeadPosition(void)
{
    while(g_pAddrHead = NULL)return;

    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }
}

void remove_list(void)
{
    ADDR *plocal;
    FILE *fp;

    if(g_pAddrHead == NULL)return;

    fp = fopen(ADDRFILE,"w+b");

    if(fp == NULL)
    {
        perror("File opening error");
    }

    SetHeadPosition();


    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        if(fp)fwrite(g_pAddrHead,1,sizeof(ADDR),fp);

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }

    g_pAddrHead = NULL;

    if(fp)fclose(fp);
}
