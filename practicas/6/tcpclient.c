#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

extern int h_errno;

void bzero(void *s, size_t n);

int main(int argc, char**argv){
    char *hostName = argv[1];
    char c;
    char *message = "GET / HTTP/1.0\r\n\r\n";
    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(hostName);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(80);
    bcopy((char *)serverInfo->h_addr,
        (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);

    int sockfd= socket(AF_INET , SOCK_STREAM, 0);
    connect(sockfd, &serverAddress, sizeof(serverAddress));
    write(sockfd, message, strlen(message));
    while(read(sockfd, &c, 1)){
        printf("%c", c);
    }



    

    return 0;
}