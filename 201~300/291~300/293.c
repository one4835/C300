#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    WSADATA wsaData;
    SOCKET s,cs;
    struct sockaddr_in   sin;
    struct sockaddr_in   cli_addr;
    int size = sizeof(cli_addr);
    char data[1000] = {0,};
    int ret;

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

    sin.sin_family      = AF_INET;
    sin.sin_port = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin)) == SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup(); return;

    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;
    }

    printf("Startup eco server...\n");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("connection failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    while(1)
    {
        memset(data,0,sizeof data);

        ret = recv(cs,data,1000,0);

        if(ret == SOCKET_ERROR)
        {
            printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
            closesocket(cs);closesocket(s);WSACleanup();return;
        }

        printf("%s had been sent\n",data);

        send(cs,data,ret,0);

        if(strcmp(data,"END") == 0)break;
    }

    if(closesocket(cs)!=0||closesocket(s)!=0)
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
