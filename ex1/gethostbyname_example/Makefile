CC = gcc

SRCS = gethostbyname.c gethostbyaddr.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)


