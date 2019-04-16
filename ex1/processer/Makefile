CC = gcc

SRCS = fork.c zombie.c wait.c waitpid.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean creatdirs $(COBJS)

creatdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)

