CC = gcc

TARGET = 

SRCS = endian_conv.c inet_addr.c inet_aton.c inet_ntoa.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))


all: clean createdirs $(COBJS)


createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@


clean:
	rm -rf $(BUILDDIR)
