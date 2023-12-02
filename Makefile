#----- Assignment 10 Makefile -----#
obj-m		:= atomic_linked_list_module.o
KERNEL_DIR	:= /lib/modules/$(shell uname -r)/build
PWD		:= $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
