#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#define DEFAULT_BUFLEN 512

#define DEFAULT_PORT "27015"
#define DEFAULT_ADDRESS "localhost"

int main()
{
    WSADATA wsaData;
    SOCKET ConnectSocket = -1;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    char *sendbuf = "Hello, Network!";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    iResult = getaddrinfo(DEFAULT_ADDRESS, DEFAULT_PORT, &hints, &result);

    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);

        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == -1) {
            closesocket(ConnectSocket);
            ConnectSocket = -1;
        }else{
            break;
        }
    }
    freeaddrinfo(result);

    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    printf("Bytes Sent: %d\n", iResult);

    iResult = shutdown(ConnectSocket, 1);

    do {
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 ){
            printf("Bytes received: %d\n", iResult);
            printf("Message received: %s\n", recvbuf);
        }
        else if ( iResult == 0 )
            printf("Connection closed\n");

    } while( iResult > 0 );

    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
