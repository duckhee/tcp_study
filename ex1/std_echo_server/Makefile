CC = gcc

SRCS = 

CFLAGS = 

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS) : $(BUILDDIR)/%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)