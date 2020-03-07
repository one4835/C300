#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }
    puts(wsaData.szDescription);
    puts(wsaData.szSystemStatus);

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);


    if(s == INVALID_SOCKET)
    {
        printf("Creating socket faliure,errorcode:%d\n",WSAGetLastError());
        WSACleanup();
        return;
    }

    if(closesocket(s)!=0)
    {
        printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup();
        return;
    }

    if(WSACleanup()!=0)
    {
        printf("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
        return;
    }

    puts("You can use winsock");
}
