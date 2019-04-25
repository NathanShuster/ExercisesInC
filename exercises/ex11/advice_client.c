/* Code from Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 30000

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_socket(char *host, char *port)
{
    struct addrinfo *res;
    struct addrinfo hints;
    int d_sock, c;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host, port, &hints, &res) == -1)
        error("Can't resolve the address");
    if (( d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1)
        error("Can't open socket");

    c = connect(d_sock, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);
    if (c == -1)
        error("Can't connect to the socket");

    return d_sock;
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        error("Can't talk to the server");

    return result;
}

int main(int argc, char *argv[])
{
    int d_sock, bytes_received;
    char buf[255], rec[256];

    struct sockaddr_in address;
    int sock = 0;
    struct sockaddr_in serv_addr;
    char * serverAddr;

    if (argc <2) { //checks that user input server ip address
      printf("Missing server ip address");
      exit(1);
    }

    serverAddr = argv[1]; //to get server ip address from command line

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serverAddr);
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, serverAddr, &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    bytes_received = recv(sock, rec, 255, 0);
    while (bytes_received) {
        if (bytes_received == EOF)
            error("can't read from server");

        rec[bytes_received] = '\0';
        printf("%s", rec);
        bytes_received = recv(sock, rec, 255, 0);
    }
    close(sock);

    return 0;
}
