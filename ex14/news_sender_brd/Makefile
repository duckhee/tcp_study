CC = gcc

SRCS = news_sender_brd.c news_receiver_brd.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

CFLAGS = 

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS): $(BUILDDIR)/%.o : %.c
	-$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)