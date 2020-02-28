#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct tagLinkeList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkeList *prev;
    struct tagLinkeList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

int add_list(ADDR*addr);
void print_list(void);
void remove_list(void);

void main(void)
{
    ADDR addr;

    puts("Enter the address to put in");
    puts("Press ENTER key to finish this program");

    while(1)
    {
        memset(&addr,0,sizeof(ADDR));

        printf("name:");gets(addr.name);

        if(strlen(addr.name)==0)break;

        printf("Phone number:");gets(addr.tel);
        printf("address:");gets(addr.addr);

        if(add_list(&addr))
        {
            printf("\nData plused in address\n\n");
        }
    }

    print_list();
    remove_list();
}

int add_list(ADDR*addr)
{
    ADDR*plocal;
    FILE*fp;

    fp = fopen("c:\\addrlist.txt","a+b");
    if(fp == NULL)
    {
        perror("File opening error");
        return 0;
    }


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

    fwrite(addr,1,sizeof(ADDR),fp);

    fclose(fp);

    return 1;
}

void print_list(void)
{
    int count = 1;
    ADDR*plocal;

    if(g_pAddrHead == NULL)return;

    plocal = g_pAddrHead;


    while(plocal->prev)
    {
        plocal = plocal->prev;
    }


    while(plocal)
    {
        printf("No.%d\n",count++);
        puts(plocal->name);
        puts(plocal->tel);
        printf("%s\n\n",plocal->addr);

        plocal = plocal->next;
    }
}

void remove_list(void)
{
    ADDR*plocal;

    if(g_pAddrHead == NULL)return;


    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }


    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }

    g_pAddrHead = NULL;
}
