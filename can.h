#ifndef CAN_H
#define CAN_H

#include <linux/can.h>

int CAN_init (const char* ifname);
int CAN_transmit (int fd, const struct can_frame* frame);

#endif
