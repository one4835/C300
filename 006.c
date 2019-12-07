#include <stdio.h>

main()
{
    int i, sum = 0;
    for (i = 1; i < 11; i++){
        sum += i;
        printf("%d\n", i);
    }
    printf("%d", sum );
}
