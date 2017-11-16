obj-m := devtest.o

KERNELDIR := ~/work/linux-3.4.39
PWD := $(shell pwd)

default:
	# 커널소스의 위치를 알려주고 빌드를 시켜야 한다.
	# 모듈로 만들어진 결과물이 어느 위치에 있어야 하는지를 정한다.
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o inputtest inputtest.c
	sudo cp devtest.ko inputtest /nfsroot

clean:
	rm -f *.o *.ko *.mod.c modules.order Module.symvers
	rm -f .*.*.cmd .*.*.*.cmd
	rm -rf .tmp_versions
	rm -f inputtest

app:
	arm-none-linux-gnueabi-gcc -o inputtest inputtest.c
