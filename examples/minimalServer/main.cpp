#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <iostream>

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define BACKLOG 10

void clientHandler(SOCKET ClientSock){
int iResult;
char recvbuf[DEFAULT_BUFLEN];
int recvbuflen = DEFAULT_BUFLEN;
int iSendResult;
do {
    iResult = recv(ClientSock, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
        printf("Bytes received: %d\n", iResult);
        printf("Message received: %s\n", recvbuf);

        iSendResult = send( ClientSock, recvbuf, iResult, 0 );
        printf("Bytes sent: %d\n", iSendResult);
    }

    else if (iResult == 0)
        printf("Connection closing...\n");
    } while (iResult > 0);

    iResult = shutdown(ClientSock, 1);

    closesocket(ClientSock);

    return;
}

int main()
{
    WSADATA wsaData;
    int iResult;
    int iThread=0;

    SOCKET ListenSocket = -1;
    SOCKET ClientSocket = -1;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);

    freeaddrinfo(result);

    while(1){

        iResult = listen(ListenSocket, BACKLOG);
        ClientSocket = accept(ListenSocket, NULL, NULL);

        std::thread t1(clientHandler,ClientSocket);
        t1.detach();

    }

    closesocket(ListenSocket);

    WSACleanup();

    return 0;
}
