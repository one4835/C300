#include <stdio.h>

void main(void)
{
    FILE *fpR,*fpW;
    char buff;
    int len;

    fpR = fopen("c:\\file.bin","rb");

    if(fpR == NULL)
    {
        perror("File read opening error");
        return;
    }

    fpW = fopen("c:\\file_copy.bin","w+b");

    if(fpW == NULL)
    {
        perror("File write opening error");
        fclose(fpR);
        return;
    }

    while(!feof(fpR))
    {
        len = fread(&buff,1,1,fpR);
        if(ferror(fpR))
        {
            perror("File reading error");
            _fcloseall();
            return;
        }

        if(len>0)
        {
            fwrite(&buff,1,1,fpW);
            if(ferror(fpW))
            {
                perror("File writing error");
                _fcloseall();
                return;
            }
        }
    }

    _fcloseall();

    puts("File copying suceed");
}
