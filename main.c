#include <stdio.h>
#include "can.h"
#include "ethernet.h"

int main (void)
{
    int vcan0 = CAN_init("can0");
    int enet = ethernet_client_connect("127.0.0.1", 8700);

    while (1);
}
