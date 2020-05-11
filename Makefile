MNAME := $(notdir $(src))
EXTRA_CFLAGS := -DMNAME=$(MNAME) -I $(src)/include -ffreestanding
EXTRA_AFLAGS := -DMNAME=$(MNAME) -I $(src)/include -ffreestanding

obj-m := $(MNAME).o
$(MNAME)-objs := module_skeleton.o $(MNAME)_main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

