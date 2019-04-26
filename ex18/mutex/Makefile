CC = gcc

SRCS = mutex.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

CFLAGS = -D_REENTRANT -lpthread

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	-$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)

