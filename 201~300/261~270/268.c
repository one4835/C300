#include <stdio.h>
#include <malloc.h>
#include <string.h>

int add_list(char*name,char*tel,char*addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkeList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkeList*prev;
    struct tagLinkeList*next;
}ADDR;

ADDR*g_pAddrHead = NULL;

void main(void)
{
    add_list("A","1111","Seoul");
    add_list("B","2222","Gyungju");
    add_list("C","3333","Gumi");
    add_list("D","4444","Busan");
    add_list("E","5555","Daegu");

    print_list();
    remove_list();
}

int add_list(char*name,char*tel,char*addr)
{
    ADDR*plocal;


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

    strcpy(g_pAddrHead->name,name);
    strcpy(g_pAddrHead->tel,tel);
    strcpy(g_pAddrHead->addr,addr);

    return 1;
}

void print_list(void)
{
    int count = 1;
    ADDR*plocal;

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
