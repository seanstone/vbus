#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "ethernet.h"

int ethernet_client_connect (char *ifname, int net_port)
{
    int fd;
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error while opening socket");
        return -1;
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(ifname),
        .sin_port = htons(net_port),
    };
    if (connect(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0) {
        perror("Error while trying to connect");
    }

    return fd;
}
