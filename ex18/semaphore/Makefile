CC = gcc

SRCS = semaphore.c

BUILDDIR = build

CFLAGS = -D_REENTRANT 

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -lpthread

clean:
	rm -rf $(BUILDDIR)
