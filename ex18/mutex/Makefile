CC = gcc

SRCS = mutex.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

CFLAGS = -D_REENTRANT

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	-$(CC) $(CFLAGS) $< -o $@ -lpthread

clean:
	rm -rf $(BUILDDIR)

