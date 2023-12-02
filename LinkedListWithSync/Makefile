#----- Assignment 10 Makefile -----#
TARGET		= ll_sync_module

obj-m		:= $(TARGET).o
$(TARGET)-y	:= ll_sync_module_main.o ll_sync.o
KERNEL_DIR	:= /lib/modules/$(shell uname -r)/build
PWD		:= $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
