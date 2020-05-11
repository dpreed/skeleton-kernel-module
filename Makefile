MNAME := $(notdir $(src))
OBJS := $(MNAME)-objs
EXTRA_CFLAGS := -D__M__=$(MNAME) -I $(src)/include -ffreestanding
EXTRA_AFLAGS := -D__M__=$(MNAME) -I $(src)/include -ffreestanding

obj-m := $(MNAME).o
$(OBJS) := module_skeleton.o
$(OBJS) += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

