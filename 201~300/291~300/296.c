#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in  sin;
    int size;
    int nTimeOut = 200;
    char buff[1000],data[1000];
    char ID[100];
    int ret;

    if("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup(); return;

        puts("Startup chatting client...");

        sin.sin_family      = AF_INET;
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_port        = htons(10000);

        if(connect(s,(struct sockaddr*)&sin,sizeof(sin)) != 0)
        {
            printf("connection failiure,errorcode %u\n",WSAGetLastError());
            closesocket(s);WSACleanup();return;
        }
    }

}
