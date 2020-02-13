#include <stdio.h>

#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

void main(void)
{
    printf("MAX: %d\n",max(5,3));
    printf("MIN: %d\n",min(5,3));
    printf("MAX: %g\n",max(3.5,4.4));
    printf("MIN: %g\n",min(3.5,4.4));
}
