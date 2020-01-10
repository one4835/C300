#include<stdio.h>
#include <string.h>

void print(struct tagAddress *pad);

struct tag Address
{
    char name[30];
    char phone[20];
    char address[100];
};

void main(void)
{
    struct tagAddress ad;

    strcpy((*pad).name," Hong gil-dong");
    strcpy((*pad).phone," 02-1234-5678");
    strcpy((*pad).address,"13th mokdong apt./Souel");

    print(&ad);
}

void print(struct tagAddress *pad)
{
    printf("name: %s\n"pad->,name);
    printf("phone: %s\n"pad->,phone);
    printf("address: %s\n",pad->address);

}
