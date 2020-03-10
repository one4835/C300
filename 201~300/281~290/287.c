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
    char data[10]={0,};

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode = %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError);
        WSACleanup();return;
    }

    sin.sin_family   =AF_INET;
    sin.sin_port     =htons(10000);
    sin.sin_addr.s_addr htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin)) == SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;
    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    printf("Waiting for connection from client...\n");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("Connection failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    printf("Connected client IP %s,port number %d\n",
        inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));

    if(recv(cs,data,3,0)<3)
    {
        printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
        closesocket(cs);closesocket(s);WSACleanup();return;
    }

    printf("%s had been sent from client\n",data);

    if(closesocket(cs)!=0||closesocket(s)!=0)

}
