#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s,cs;
    WSADATA wsaData;
    struct sockaddr_in   sin;
    struct sockaddr_in   cli_addr;
    int size sizeof(cli_addr);
    char data[10] = {0,};

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode = %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    sin.sin_family     = AF_INET;
    sin.sin_port       = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin))== SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;

    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode failiure,errorcode = %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    printf("Waiting connection from client...\n");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("Connection failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }
}
