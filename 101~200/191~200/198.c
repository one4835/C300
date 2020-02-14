#include <stdio.h>

#define COUNT 100

#if defined COUNT
#undef COUNT
#define COUNT 99
#else
#define COUNT 88
#endif

void main(void)
{
    printf("COUNT : %d\n",COUNT);
}
