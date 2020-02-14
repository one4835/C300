#include <stdio.h>

void main(void)
{
    printf("filename: %s\n",__FILE__);
    printf(" d a t e: %s\n",__DATE__);
    printf(" t i m e: %s\n",__TIME__);
    printf(" l i n e: %d\n",__LINE__);
}
