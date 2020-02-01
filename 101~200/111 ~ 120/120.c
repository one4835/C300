#include<stdio.h>
#include <string.h>

struct tag Address
{
    char name[30];
    char phone[20];
    char address[100];
};

void main(void)
{
    struct tagAddress ad;
    struct tagAddress*pad;

    pad =&ad;

    strcpy((*pad).name," Hong gil-dong");
    strcpy((*pad).phone," 02-1234-5678");
    strcpy((*pad).address,"13th mokdong apt./Souel");

    printf("name: %s\n",ad.name);
    printf("phone: %s\n",ad.phone);
    printf("address: %s\n",ad.address);

}
