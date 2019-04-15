CC = gcc

TARGET = test

SRCS = hello_server.c hello_client.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.c=.o))

#종속 되는  build는 밑에 있어야한다.


#%.o: 
#	gcc -o $@ $<

all: clean createdirs $(COBJS)


createdirs:
	$(shell mkdir ${BUILDDIR})


$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@
#	$(CC) -o $@ $^


clean:
	rm -rf build
	rm -f hello_server
	rm -f hello_client

server:
	$(CC) -o hello_server hello_server.c

client:
	$(CC) -o hello_client hello_client.c



