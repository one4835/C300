#include <stdio.h>

void main(void)
{
    char        *p_char;
    short       *p_short;
    int         *p_int;
    long        *p_long;
    float       *p_float;
    double      *p_double;

    printf("charactor : %d byte\n",sizeof(char));
    printf("integer : %d byte\n",sizeof(short));
    printf("integer : %d byte\n",sizeof(int));
    printf("integer : %d byte\n",sizeof(long));
    printf("real : %d byte\n",sizeof(float));
    printf("real : %d byte\n",sizeof(double));

    printf("charactor pointer: %d byte\n",sizeof(p_char));
    printf("integer pointer: %d byte\n",sizeof(p_short));
    printf("integer pointer: %d byte\n",sizeof(p_int));
    printf("integer pointer: %d byte\n",sizeof(p_long));
    printf("real pointer: %d byte\n",sizeof(p_float));
    printf("real pointer: %d byte\n",sizeof(p_double));
}
