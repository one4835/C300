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
    char data[1024] = {0,};
    int ret;
    FILE *fp;
    int nTimeOut = 3000;

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
    sin.sin_port        = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s,(struct sockaddr*)&sin,sizeof(sin)) == SOCKET_ERROR)
    {
        printf("Bind failiure,errorcode = %d\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;

    }

    if(listen(s,SOMAXCONN)!=0)
    {
        printf("Listen mode setting failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s);WSACleanup();return;
    }

    printf("Waiting for the connection from client...\n");

    cs = accept(s,(struct sockaddr*)&cli_addr,&size);

    if(cs == INVALID_SOCKET)
    {
        printf("connection failiure,errorcode %d\n",WSAGetLastError());
        closesocket(s); WSACleanup();return;
    }

    fp = fopen("c:\\recv.bin","w+b");

    if(fp == NULL)
    {
        perror("File creation error");
        closesocket(cs);closesocket(s); WSACleanup();return;
    }

    setsockopt(cs,SOL_SOCKET,SO_RCVTIMEO,(char*)&nTimeOut,
      size);
      while(1)
      {
          ret = recv(cs,data,1024,0);

          if(ret == 0)break;

          if(ret == SOCKET_ERROR)
          {
              printf("Sending error,errorcode (%u)\n",WSAGetLastError());
              closesocket(cs);
              closesocket(s);
              WSACleanup();
              return;
          }

          fwrite(data,1,ret,fp);
          printf("Sent %dbyte\n",ret);
      }

      fclose(fp);

      shutdown(s,SD_BOTH);

      if(closesocket(cs)!=0||closesocket(s)!=0)
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
