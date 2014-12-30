
obj-m += tz_check_module.o

all:
		make ARCH=arm CROSS_COMPILE=/home/machiry/workdir/projects/TegraK1/toolset/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf- -C $(KSRC) M=$(PWD) modules
clean:
		make -C $(KSRC) M=$(PWD) clean
