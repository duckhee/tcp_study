CC = gcc

SRCS = echo_server.c echo_client1.c echo_client2.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)


