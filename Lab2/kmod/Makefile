kmod=kmod
user=user
path=/home/ivan/Documents/OS1/Makefile
obj-m += $(kmod).o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	make user
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	make rm_user
insmod:
	sudo insmod $(kmod).ko
rmmod:
	sudo rmmod $(kmod).ko
user:
	gcc -o $(user) $(user).c
rm_user:
	rm $(user)
runmod:
	sudo ./$(user) $(path)


