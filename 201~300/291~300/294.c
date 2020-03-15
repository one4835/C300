#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    struct sockaddr_in  sin;
    char data[100];

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup();return;
    }

    sin.sin_family      = AF_INET
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port        = htons(10000);

    if(connect(s,(struct sockaddr*)&sin,sizeof(sin))!=0)
    {
        printf("connection failiure,errorcode %u\n",WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    puts("Startup eco client.");
    puts("Enter the data to send and press enter");
    puts("To exit, enter END");

    while(1)
    {
        printf("Enter the data to send:");
        gets(data);

        if(send(s,data,strlen(data),0)<strlen(data))
        {
            printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
            closesocket(s);WSACleanup();return;
        }

        if(recv(s,data,1000,0)== SOCKET_ERROR)
        {
            printf("Data sending failiure,errorcode %u\n",WSAGetLastError());
            close socket(s);WSACleanup();return;
        }

        printf("\n%s had been eco.\n\n",data);

        if(strcmp(data,"END")==0)break;
    }

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
