#include <stdio.h>
#include "can.h"

int main (void)
{
    int vcan0 = CAN_init("can0");

    struct can_frame frame = {
        .can_id  = 0x123,
        .can_dlc = 2,
        .data = {0x11, 0x22},
    };
	int n = CAN_transmit(vcan0, &frame);
	printf("Wrote %d bytes\n", n);
}
