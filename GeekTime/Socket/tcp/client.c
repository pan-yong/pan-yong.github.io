#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MESSAGE_SIZE 102400

void send_data(int sockfd) {

}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2){
        printf("usage:tcpclient <IPaddress>");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = 12345;
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    
    int connect_rt = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if (connect_rt < 0) {
        printf("connect failed");
        exit(EXIT_FAILURE);
    }

    send_data(sockfd);
    return 0;
}

