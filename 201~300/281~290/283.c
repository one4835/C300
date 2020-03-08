#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s,cs;
    WSADATA wsaData;
    struct sockaddr_in  sin;
    struct sockaddr_in  cli_addr;
    int size = sizeof(cli_addr);

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure, errorcode%d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s== INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup();
        return;
    }

    sin.sin_family      = AF_INET;
    sin.sin_port        = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(binds(s,(struct sockaddr*)&sin,sizeof(Sin)) == SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    printf("Waiting Connection from client...\n");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("Connection,error code %d\n",WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    puts("Connected with client");

    if(closesocket(cs)!=0||closesocket(s)!=0)
    {
        printf("Socket remove failiure,errorcode = %u\n",WSAGetLastError());
        WSACleanup();
        return;
    }

    if(WSACleanup()!=0)
    {
        printf("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
        return;
    }
}
