#----- Assignment 10 Makefile -----#
TARGET		= atomic_practice_module

obj-m		:= $(TARGET).o
$(TARGET)-y	:= atomic_practice_module_main.o
KERNEL_DIR	:= /lib/modules/$(shell uname -r)/build
PWD		:= $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
