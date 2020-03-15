#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    WSADATA wsaData;
    SOCKET s,cs;
    struct sockaddr_in  sin;
    struct sockaddr_in  cli_addr;
    int size = sizeof(cli_addr);
    char buff[1000],data[1000];
    int nTimeOut = 200;
    char ID[100];
    int ret;

    if(WSAStartup(WINSOCK_VERSION,&wsaData) != 0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    sin.sin_family      = AF_INET;
    sin.sin.port        = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin)) == SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup(); return;

    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    puts("Startup chatting server...");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("connection failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    printf("Enter the nickname to use at chatting:");
    gets(ID);
    puts("Press enter after entering message");

    size = sizeof(int);
    setsockopt(cs,SOL_SOCKET,SO_RCVTIMEO,(char*)&nTimeOut,size);

    while(1)
    {
        if(kbhit())
        {
            gets(buff);
            if(strcmp(buff,"END") == 0)
            {
                send(s,"END",3,0);
                break;
            }

            sprintf(data,"%s:%s",ID,buff);

            if(send(cs,data,strlen(data),0)<strlen(data))
            {
                printf("Sending failiure,errorcode %u\n",WSAGetLastError());
                closesocket(cs);closesocket(s); WSACleanup();return;
            }
        }

        memset(data,0,sizeof data);
        ret = recv(cs,data,1000,0);

        if(ret == SOCKET_ERROR)
        {
            printf("chatting failiure,errorcode %u\n",WSAGetLastError());
            closesocket(cs);closesocket(s); WSACleanup();return;
        }

        puts(data);
    }

    if(closesocket(cs) != 0 || closesocket(s) != 0)
    {
        printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup()!=0)
    {
        printf)+("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
        return;
    }
}
