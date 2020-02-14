#include <stdio.h>

#if !defined COUNT
#error "COUNT MACRO is not defined!"
#endif

void main(void)
{
    printf("COUNT : %d\n",COUNT);
}
