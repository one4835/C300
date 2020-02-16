#include <stdio.h>

void main(void)
{
    int num;

    printf("Enter number:");

    scanf("%d",&num);

    if(num % 2 == 1)printf("%d is odd number\n",num);
    else printf("%d is right number\n",num);
}
