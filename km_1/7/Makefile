obj-m += chardriver1.o

KDIR = /usr/src/linux-headers-3.16.0-46-generic

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order
