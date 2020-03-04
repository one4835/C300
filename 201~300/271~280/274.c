#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#define ADDRFILE        "c:\\addrlist.txt"

typedef struct tagLinkeList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkeList*prev;
    struct tagLinkeList*next;
}ADDR;

ADDR *g_pAddrHead = NULL;
ADDR *g_pFind;
int g_bSaved = 1;

void get_addrlist(void);
int add_list(const ADDR *addr);
int find_list(const char *name);
void SetHeadPosition(void);
void SetTailPosition(void);

void Add_addr(void);
void Find_addr(void);
void Motify_addr(void);
void Delete_addr(void);
void Print_addr(void);
void Save_addr(void);
void Remove_addr(void);

void main(void)
{
    int ch;

    get_addrlist();

    puts("Address program Version 1.0.0");

    while(1)
    {
        printf("\n[1]New[2]search[3]change[4]remove[5]print[S]save[Q]quit");

        ch = getch();

        switch(ch)
        {
            case'1' : Add_addr();break;
            case'2' : Find_addr();break;
            case'3' : Motify_addr();break;
            case'4' : Delete_addr();break;
            case'5' : Print_addr();break;
            case's' :
            case'S' : Save_addr();break;
            case'q' :
            case'Q' :
                if(g_bSaved == 0)
                {
                    printf("\n\nWill you save the changed address data(y/n)?");
                        ch = getchar();
                        if(ch == 'Y'||ch == 'y')Save_addr();
                }

                Remove_addr();return;
            default :printf("\n\n Press 1~5 orS/Q\n\n");break;
        }
    }
}

void get_addrlist(void)
{
    ADDR addr;
    FILE*fp;

    fp =fopen(ADDRFILE,"rb");

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

        if(add_list(&addr)== 0)
        {
            printf("Can't plus the address data to Linked List.\n");
        }
    }

    fclose(fp);
}

int add_list(const ADDR*addr)
{
    ADDR *plocal,*pn = g_pAddrHead;

    SetHeadPosition();


    if(g_pAddrHead == NULL)
    {
        plocal = malloc(sizeof(ADDR));
        memset(plocal,0,sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        g_pAddrHead = plocal;
        g_pAddrHead->prev = NULL;
        g_pAddrHead->next = NULL;
    }
    else
    {
        plocal = malloc(sizeof(ADDR));
        memset(plocal,0,sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        while(pn->next)
        {
            pn = pn->next;
        }

        pn->next = plocal;
        plocal->prev = pn;
        plocal->next = NULL;
    }

    strcpy(plocal->name,addr->name);
    strcpy(plocal->tel,addr->tel);
    strcpy(plocal->addr,addr->addr);

    return 1;
}

void SetHeadPosition(void)
{
    if(g_pAddrHead == NULL)return;

    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }
}

void SetTailPosition(void)
{
    if(g_pAddrHead == NULL)return;

    while(g_pAddrHead->next)
    {
        g_pAddrHead = g_pAddrHead->next;
    }
}

int find_list(const char *name)
{
    ADDR *plocal;

    SetHeadPosition();

    plocal = g_pAddrHead;

    while(plocal)
    {
        if(strstr(plocal->name,name))
        {
            g_pFind = plocal;
            return 1;
        }
        plocal = plocal->next;
    }

    return 0;
}

void Add_addr(void)
{
    ADDR addr;

    memset(&addr,0,sizeof(ADDR));

    printf("\n\nNmae to plus:");gets(addr.name);

    if(strlen(addr.name)== 0)return;

    printf("Phonenumber to plus:");gets(addr.tel);
    printf("Address to plus:");gets(addr.addr);

    if(strlen(addr.name)== 1)
    {
        printf("\nIt's already plused name\n\n");
        puts(g_pFind->name);
        puts(g_pFind->tel);
        puts(g_pFind->addr);
        return;
    }

    if(add_list(&addr))
    {
        g_bSaved = 0;
        printf("\nPlused\n\n");
    }
    else
    {
        printf("\nPlusing failiure\n\n");
    }
}

void Find_addr(void)
{
    char buff[100]={0,};
    ADDR *plocal;

    printf("\n\nEnter the part of the name/phonenumber/address to search\n");
    printf("Name/phonenumber/address:");gets(buff);

    if(strlen(buff)== 0)return;

    SetHeadPosition();

    plocal = g_pAddrHead;
    g_pFind = NULL;

    while(plocal)
    {
        if(strstr(plocal->name,buff))
        {
            g_pFind = plocal;
            break;
        }

        if(strstr(plocal->tel,buff))
        {
            g_pFind = plocal;
            break;
        }

        if(strstr(plocal->addr,buff))
        {
            g_pFind = plocal;
            break;
        }

        plocal = plocal->next;
    }

    if(g_pFind)
    {
        puts(g_pFind->name);
        puts(g_pFind->tel);
        puts(g_pFind->addr);
    }
    else
    {
        printf("\n\nCan't find %s in the address\n\n",buff);
    }
}

void Motify_addr(void)
{
    char name[100]={0,};
    ADDR addr;

    while(1)
    {
        printf("\n\nName to change:");gets(name);

        if(strlen(name)==0)return;

        if(find_list(name)==0)
        {
            puts("Can't find the name to change");
            continue;
        }
        break;
    }

    printf("\nAddress data about %s is like under\n\n",name);
    puts(g_pFind->name);
    puts(g_pFind->tel);
    puts(g_pFind->addr);

    printf("\n\nEnter the name/phonenumber/address to change and press enter\n\n");

    printf("name:");gets(addr.name);
    printf("phonenumber:");gets(addr.tel);
    printf("address:");gets(addr.addr);

    if(strlen(addr.name)==0)strcpy(addr.name,name);

    strcpy(g_pFind->name,addr.name);
    strcpy(g_pFind->tel,addr.tel);
    strcpy(g_pFind->addr,addr.addr);

    g_bSaved = 0;

    printf("Changed the address data for %s\n",name);
}

void Delete_addr(void)
{
    char name[100] = {0,};
    ADDR *plocal;
    int ch;

    while(1)
    {
        printf("\n\n Name to delete:");gets(name);

        if(strlen(name)==0)return;

        if(find_list(name)==0)
        {
            puts("Can't find the name to delete");
            continue;
        }
        break;
    }

    puts(g_pFind->name);
    puts(g_pFind->tel);
    puts(g_pFind->addr);

    printf("Would you delete %s(y/n)?",name);
    ch = getch();
    fflush(stdin);

    if(ch =='Y'||ch =='y')
    {
        if(g_pFind->prev == NULL)
        {
            if(g_pFind->next == NULL)
            {
                free(g_pFind);
                g_pAddrHead =NULL;
            }
            else
            {
                plocal = g_pFind->next;
                free(g_pFind);
                plocal->prev = NULL;
                g_pAddrHead = plocal;
            }
        }

        else if(g_pFind->next == NULL)
        {
            plocal = g_pFind->prev;
            free(g_pFind);
            plocal->next = NULL;
            g_pAddrHead = plocal;
        }

        else
        {
            plocal = g_pFind->prev;
            plocal->next = g_pFind->next;

            plocal = g_pFind->next;
            plocal->prev = g_pFind->prev;

            free(g_pFind);
            g_pAddrHead = plocal;
        }

        g_bSaved = 0;

        printf("\n\nSearched address data deleted\n\n");
    }
}

void Print_addr(void)
{
    int count = 1;
    ADDR*plocal;

    SetHeadPosition();

    plocal = g_pAddrHead;


    while(plocal->prev)
    {
        plocal = plocal->prev;
    }

    printf("\n\n");


    while(plocal)
    {
        printf("Number.%d\n",count++);
        puts(plocal->name);
        puts(plocal->tel);
        printf("%s\n\n",plocal->addr);

        printf("Press any key,(Quit:Q)\n\n");
        if(getch()=='q')return;

        plocal = plocal->next;
    }
}

void Save_addr(void)
{
    ADDR*plocal;
    FILE *fp;

    if(g_pAddrHead == NULL)return;

    fp = fopen(ADDRFILE,"w+b");

    if(fp == NULL)
    {
        perror("File opening");
        return;
    }

    SetHeadPosition();


    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        fwrite(g_pAddrHead,sizeof(ADDR),1,fp);

        g_pAddrHead = plocal;
    }

    printf("\n Saved all data in the file");
    g_bSaved = 1;

    fclose(fp);
}

void Remove_addr(void)
{
    ADDR *plocal;

    if(g_pAddrHead == NULL)return;

    SetHeadPosition();


    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }

    g_pAddrHead = NULL;
}
