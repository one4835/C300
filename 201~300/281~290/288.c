#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    int nSize = 1048576;
    int size = sizeof(int);

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

    getsocket(s,SOL_SOCKET,SO_SNDBUF,(char*)&nSize,&size);
    printf("Buffer's size set to %d\n",nSize);

    getsocket(s,SOL_SOCKET,SO_RCVBUF,(char*)&nSize,&size);
    printf("Buffer's size set to %d\n",nSize);

    setsockopt(s,SOL_SOCKET,SO_SNDBUF,(char*)&nSize,&size);
    setsockopt(s,SOL_SOCKET,SO_RCVBUF,(char*)&nSize,&size);

    getsockopt(s,SOL_SOCKET,SO_SNDBUF,(char*)&nSize,&size);
    printf("Buffer's size set to %d\n",nSize);

    getsockopt(s,SOL_SOCKET,SO_RCVBUF,(char*)&nSize,&size);
    printf("Buffer's size set to %d\n",nSize);

    if(closesocket(s)!=0)
    {
        printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup();return;
    }

    if(WSACleanup()!=0)
    {
        printf("WSACleanup failiure,errorcode %u\n"WSAGetLastError());
        return;
    }
}
