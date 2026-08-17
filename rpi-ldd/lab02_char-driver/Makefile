obj-m += hello_char.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

.PHONY: all clean load unload logs

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

load:
	sudo insmod hello_char.ko

unload:
	sudo rmmod hello_char

logs:
	sudo dmesg | grep hello_char | tail -n 20