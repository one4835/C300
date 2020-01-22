#include <stdio.h>
#include <direct.h>

void main(void)
{
    int drive;

    drive = _getdrive();

    printf("drive now :%c\n",'A' + drive - 1);
}
