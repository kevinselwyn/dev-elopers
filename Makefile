NAME  := dev-elopers
obj-m := $(NAME).o
KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

all: build

build: $(NAME).c $(NAME).mp3
	xxd -i $(NAME).mp3 > $(NAME).h
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -f .*.cmd *.h *.ko *.mod.c *.o *.symvers *.order
	rm -rf .tmp_versions

install: build
	cp elopers.rules /etc/udev/
	chmod +x /etc/udev/elopers.rules
	ln -s /etc/udev/elopers.rules /etc/udev/rules.d/010_elopers.rules
	insmod ./$(NAME).ko

uninstall:
	rm -f /etc/udev/elopers.rules
	rm -f /etc/udev/rules.d/010_elopers.rules
	rmmod $(NAME)