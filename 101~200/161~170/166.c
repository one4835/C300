#include <stdio.h>
#include <direct.h>

void main(void)
{
    int drive = 4;

    if(_chdrive(drive)== 0)
    {
    drive = _getdrive();
    printf("drive changed :%c\n",'A' + drive - 1);
    }
}
