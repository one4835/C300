#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    struct sockaddr_in sin;
    char data[10]="abc";

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup();return;
    }

    sin.sin_family      = AF_INET
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port        = htons(10000);

    if(connect(s,(struct sockaddr*)&sin,sizeof(sin))!=0)
    {
        printf("Connection failiure,errorcode %u\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;
    }

    if(send(s,data,3,0)<3)
    {
        printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;
    }

    puts("Sent 'abc' to server program");

    shutdown(s,SD_BOTH);

    if(closesocket(s)!=0)
    {
        printf("Socket remove failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup();return;
    }

    if(WSACleanup()!=0)
    {
        printf("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
        return;
    }
}
