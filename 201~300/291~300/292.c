#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

void main(int argc,char *argv[])
{
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in  sin;
    unsigned short i;

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode:%d\n",WSAGetLastError());
        WSACleanup();return;
    }

    for(i=1;i<65535;i++)
    {
        sin.sin_family      = AF_INET;
        sin.sin_addr.s_addr = inet_addr("127.0.0.1")
        sin.sin_port        = htons(i);

        if(connect(s,(struct sockaddr*)&sin,sizeof(sin)) == 0)
        {
            printf("\n %5d port using\n",i);
            closesocket(s);

            s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

            if(s == INVALID_SOCKET)
            {
                printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
                WSACleanup();return;
            }
        }
        else
        {
            printf(".");
        }
    }

    if(closesocket(s)!=0)
    {
        printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
        WSACleanup();return;
    }

    if
}
