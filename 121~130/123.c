#include <stdio.h>
#include <string.h>

struct tagAddress
{
    char name[30];
    char phone[20];
    char address[100];
};

void main (void)
{
    struct tagAddress ad[3];
    struct tagAddress *pad;
    int i;

    pad = ad;

    for(i=0;i<3;i++)
    {
        sprintf(pad[i].name,"gil-dong Hong%d",i);
        sprintf(pad[i].phone,"02-1234-5678");
        sprintf(pad[i].address,"13th mokdong apt.Souel",i);
    }

    for(i=0;i<3;i++)
    {
        printf("name: %s\n",pad[i].name);
        printf("phone: %s\n",pad[i].phone);
        printf("address: %s\n",pad[i].address);
    }
}
