#include <winsock2.h>
#include <windows.h>
#include <strings.h>

#include "functions.h"

#pragma comment(lib, "ws2_32.lib")

#define NO_FLAGS_SET 0
#define PORT 80
#define MAXBUFLEN 20480
#define REQUEST_SIZE 200

int main(){
    WSADATA Data;
    SOCKADDR_IN recvSockAddr;
    SOCKET recvSocket;
    int status;
    int numrcv = 0;
    struct hostent * remoteHost;
    char * ip;
    const char * host_name = "pb-homework.appspot.com";
    char buffer[MAXBUFLEN];

    memset(buffer,0,MAXBUFLEN);
    status = WSAStartup(MAKEWORD(2, 2), &Data);

    if(status != 0)
    {
        printf("ERROR: WSAStartup unsuccessful\r\n");
        return 0;
    }

	remoteHost = gethostbyname(host_name);
	ip = inet_ntoa(*(struct in_addr *)*remoteHost->h_addr_list);
	printf("IP address is: %s.\n", ip);
    memset(&recvSockAddr, 0, sizeof(recvSockAddr));
    recvSockAddr.sin_port=htons(PORT);
    recvSockAddr.sin_family=AF_INET;
    recvSockAddr.sin_addr.s_addr= inet_addr(ip);
	recvSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(recvSocket == INVALID_SOCKET)
	{
		printf("ERROR: socket unsuccessful\r\n");
             WSACleanup();
		system("pause");
		return 0;
	}

    if(connect(recvSocket,(SOCKADDR*)&recvSockAddr,sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        printf("ERROR: socket could not connect\r\n");
        closesocket(recvSocket);
        WSACleanup();
        return 0;
    }

    char request[REQUEST_SIZE];
    sprintf(request, "GET /var/1 HTTP/1.1\r\nHost:%s\r\n\r\n", host_name);

    char * buffer_p = function_request(recvSocket, request, buffer, MAXBUFLEN);

    char * p = function_secret(buffer_p);

    sprintf(request, "GET /var/1?secret=%s HTTP/1.1\r\nHost:%s\r\n\r\n", p, host_name);
    buffer_p = function_request(recvSocket, request, buffer, MAXBUFLEN);

    int size = strlen(buffer_p);
    char list[size];
    function_list(list, buffer_p);

    char strmax[size];
    function_nameOfMax(list, size, strmax);

    char result[size];
    sprintf(result, "result=%s", strmax);
    printf("%s\n\n", result);

    sprintf(request, "POST %s/var/1 HTTP/1.1\r\n"
            "Content-length: %d\r\n\r\n"
            "%s", host_name, strlen(result), result);
    function_request(recvSocket, request, buffer, MAXBUFLEN);
    return 0;
}
