#include <stdio.h>

#define FILEREAD    4096

void main(void)
{
    FILE *fpR1,*fpR2,*fpW;
    char buff[FILEREAD];
    int len;

    fpR1 = fopen("c:\\file.bin","rb");

    if(fpR1 == NULL)
    {
        perror("File opening error");
        return;
    }

    fpR2 = fopen("c:\\file_copy.bin","rb");

    if(fpR2 == NULL)
    {
        perror("File reading open error");
        _fcloseall();
        return;
    }

    fpW = fopen("c:\\file2.bin","w+b");

    if(fpW == NULL)
    {
        perror("File writing open error");
        _fcloseall();
        return;
    }

    while(!feof(fpR1))
    {
        len = fread(buff,1,FILEREAD,fpR1);
        if(ferror(fpR1))
        {
            perror("File reading error 1");
            _fcloseall();
            return;
        }

        if(len>0)
        {
            fwrite(buff,1,len,fpW);
            if(ferror(fpR2))
            {
                perror("File writing error 1");
                _fcloseall();
                return;
            }
        }
    }

    while(!feof(fpR2))
    {
        len = fread(buff,1,FILEREAD,fpR2);
        if(ferror(fpR2))
        {
            perror("File reading error 2");
            _fcloseall();
            return;
        }

        if(len>0)
        {
            fwrite(buff,1,len,fpW);
            if(ferror(fpR2))
            {
                perror("File writing error 2");
                _fcloseall();
                return;
            }
        }
    }

    _fcloseall();

    puts("File combining suceed");
}
