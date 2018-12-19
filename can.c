#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "can.h"

int CAN_init (const char* ifname)
{
    int fd;
	if ((fd = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Error while opening socket");
		return -1;
	}

    struct ifreq ifr;
    strcpy(ifr.ifr_name, ifname);
	ioctl(fd, SIOCGIFINDEX, &ifr);
	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

    struct sockaddr_can addr = {.can_family  = AF_CAN, .can_ifindex = ifr.ifr_ifindex};
	if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("Error in socket bind");
		return -2;
	}

    return fd;
}

int CAN_transmit (int fd, const struct can_frame* frame)
{
    return write(fd, frame, sizeof(struct can_frame));
}
