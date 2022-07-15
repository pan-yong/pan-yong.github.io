/************************************************
    Created Time: 四  4/14 21:54:33 2022
    Author: durianpy@icloud.com 
    File Name: hello_client.c
************************************************/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	servaddr.sin_port = htons(1234);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	char message[1024] = {0};
	read(sockfd, message, sizeof(message)-1);
	printf("Message from server: %s\n", message);

	close(sockfd);
	return 0;
}
