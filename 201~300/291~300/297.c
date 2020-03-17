#include <stdio.h>
#include <winsock2.h>

#define USERFILE"c:\\userrid.txt"

void getid(void);

#pragma comment(lib,"wsock32.lib")

typedef struct tagIDList
{
    char  uid[9];
    char  pwd[9];
}IDLIST id[100];

void main(void)
{
    WSADATA wsaData;
    SOCKET s,cs;
    struct sockaddr_in  sin;
    struct sockaddr_in  cli_addr;
    char data[1000];
    int size = sizeof(cli_addr);
    int ret,i;
    IDLIST login;

    getid();

    if(WSAStartup(WINSOCK_VERSION,&wsaData)!=0)
    {
        printf("WSAStartup failiure,errorcode %d\n",WSAGetLastError());
        return;
    }

    s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("Socket creation failiure,errorcode %d\n",WSAGetLastError());
        WSACleanup(); return;
    }

    sin.sin_family      = AF_INET;
    sin.sin_port        = htons(12345);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin))==SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;

    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup(); return;
    }

    puts("Startup server...");

    while(1)
    {
        cs = accept(s,(struct sockaddr*)&cli_addr,&size);

        if(cs == INVALID_SOCKET)
        {
            printf("connection failiure,errorcode %d\n",WSAGetLastError());
            closesocket(s);WSACleanup();return;
        }

        memset(data,0,sizeof data);
        ret = recv(cs,data,1000,0);

        if(ret == SOCKET_ERROR)
        {
            printf("Sending failiure,errorcode %u\n",WSAGetLastError());
            closesocket(cs); closesocket(s); WSACleanup(); return;
        }

        memset(&login,0,sizeof(login));
        strncpy(login.uid,&data[0],8);
        strncpy(login.pwd,&data[8],8);

        for(i=7;i>=0;i--)
        {
            if(isspace(login.uid[i]))login.uid[i]=0;
            if(isspace(login.pwd[i]))login.pwd[i]=0;
        }

        for(i=0;i<100;i++)
        {
            if(strcmmp(login.uid,id[i].uid)==0)
            {
                if(strcmp(login.pwd,id[i].pwd)==0)
                {
                    printf("User %s has connected\n",login.uid);
                    send(cs,"1",1,0);
                    break;
                }
                else
                {
                    printf("User %s's password is not correct\n",
                        login.uid);
                    send(cs,"2",1,0);
                    break;
                }
            }
        }

        if(i == 100)
        {
            printf("User that is not in data had tried login\n");
            printf("User ID :%S\n",login.uid);
            send(cs,"3",1,0);
        }

        closesocket(cs);
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

void getid(void)
{
    FILE *fp;
    int i,j;
    char buff[100];

    fp = fopen(USERFILE,"r");

    for(i=0;i<100;i++)
    {
        fgets(buff,20,fp);
        strncpy(id[i].uid,&buff[0],8);
        strncpy(id[i].pwd,&buff[8],8);

        for(j=7;j>=0;j--)
        {
            if(isspace(id[i].uid[j]))id[i].uid[j]=0;
            if(isspace(id[i].pwd[j]))id[i].pwd[j]=0;
        }
    }

    fclose(fp);
}
