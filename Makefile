CFLAGS += -I. -std=gnu11 -O3

bin/fsw: $(wildcard *.c)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: vcan vcan-del
vcan: /sys/class/net/can0

/sys/class/net/can0:
	sudo modprobe vcan
	sudo ip link add dev can0 type vcan
	sudo ip link set up can0

vcan-del:
	sudo ip link del dev can0

.PHONY: clean
clean: vcan-del
	rm -rf bin
