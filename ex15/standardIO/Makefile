CC = gcc

SRCS = syscpy.c stdcpy.c desto.c todes.c

BUILDDIR = build

CFLAGS = 

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS) : $(BUILDDIR)/%.o : %.c
	-$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)

