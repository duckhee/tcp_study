CC = gcc

TARGET = 

SRCS = hell_server.c hello_client.c

mkdirs:
	$(shell mkdir build)

COBJS: %.o : %.c

%.o:
	gcc -o $@ $<

all: mkdirs

clean:
	rm -rf build
	rm -f hello_server
	rm -f hello_client

server:
	$(CC) -o hello_server hello_server.c

client:
	$(CC) -o hello_client hello_client.c



