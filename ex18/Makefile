CC = gcc

SRCS = thread1.c thread2.c thread3.c thread4.c 

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

CFLAGS = -lpthread

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	-$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILDDIR)

