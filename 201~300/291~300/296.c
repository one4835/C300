#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

//#pragma warning(disable: 4101)
#pragma comment(lib,"wsock32.lib")

void main(void)
{
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in  sin;
    int size;
    int nTimeOut = 200;
    char buff[1000],data[1000];
    char ID[100];
    int ret;

    if("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup(); return;

        puts("Startup chatting client...");

        sin.sin_family      = AF_INET;
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_port        = htons(10000);

        if(connect(s,(struct sockaddr*)&sin,sizeof(sin)) != 0)
        {
            printf("connection failiure,errorcode %u\n",WSAGetLastError());
            closesocket(s);WSACleanup();return;
        }

        size = sizeof(int);
        setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char*)&nTimeOut,
        size);

        printf("Put the nickname that you'll use on the chatting:");
        gets(ID);
        puts("Press ENTER after putting message.");

        while(1)
        {
            if(kbhit())
            {
                gets(buff);
                if(strcmp(buff,"END")==0)
                {
                    send(s,"END",3,0);
                    break;
                }

                sprintf(data,"%s:%s",ID,buff);

                if(send(s,data,strlen(data),0)<strlen(data))
                {
                    printf("Sending failiure,errorcode %u\n",WSAGetLastError());
                    closesocket(s); WSACleanup(); return;
                }
            }

            memset(data,0,sizeof data);
            ret = recv(s,data,1000,0);

            if(ret == SOCKET_ERROR)
            {
                printf("Sending failiure,errorcode %u\n",WSAGetLastError());
                closesocket(s); WSACleanup(); return;
            }

            puts(data);

            if(strcmp(data,"END")==0)break;
        }

        if(closesocket(s)!=0)
        {
            printf("Socket removing failiure,errorcode %u\n",WSAGetLastError());
            WSACleanup(); return;
        }

        if(WSACleanup()!=0)
        {
            printf("WSACleanup failiure,errorcode %u\n",WSAGetLastError());
            return;
        }
    }

}
