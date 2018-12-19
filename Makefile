CFLAGS += -I. -std=gnu11 -O3

bin/fsw: $(wildcard *.c)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: vcan vcan-del
vcan: /sys/class/net/vcan0

/sys/class/net/vcan0:
	sudo modprobe vcan
	sudo ip link add dev vcan0 type vcan
	sudo ip link set up vcan0

vcan-del:
	sudo ip link del dev vcan0

.PHONY: clean
clean: vcan-del
	rm -rf bin
