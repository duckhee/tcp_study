CC = gcc

SRCS = dup.c sep_serv.c sep_client.c

BUILDDIR = build

CFLAGS = 

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS): $(BUILDDIR)/%.o : %.c
	-$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)
