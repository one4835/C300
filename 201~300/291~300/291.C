#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(int argc,char *argv[])
{
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in  sin;
    char data[1024];
    FILE *fp;
    int ret;
    int nRead;

    if(argc<2)
    {
        printf("Enter the file name to send\n");
        printf("ex)291.exe sample.txt\n");
        return;
    }

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }
    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation,errorcode:%d\n",WSAGetLastError());
        WSACleanup();return;
    }

    sin.sin_family      = AF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port        = htons(10000);

    if(connect(s,(struct sockaddr*)&sin,sizeof(sin))!=0)
    {
        printf("connection failiure,errorcode %u\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    fp = fopen(argv[1],"rb");

    if(fp == NULL)
    {
        perror("File opening error");
        closesocket(s);WSACleanup();return;
    }

    while(1)
    {
        nRead = fread(data,1,1024,fp);

        if(ferror(fp))
        {
            perror("File reading error");
            closesocket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        ret= send(s,data,nRead,0);

        if(ret == SOCKET_ERROR||ret!= nRead)
        {
            printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
            closesocket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        printf("Sent %dbyte\n",ret);
        if(feof(fp))break;
    }

    fclose(fp);

    printf("Sent %s file\n",argv[1]);

    shutdown(s,SD_BOTH);

    if(closesocket(s)!=0)
    {
        printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup();return;
    }

    if(WSACleanup()!=0)
    {
        printf("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
        return;
    }
}
