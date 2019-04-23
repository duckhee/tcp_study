CC = gcc

TARGET = 

SRCS = hello_server.c tcp_client.c

BUILD = build



COBJS = $(addprefix $(BUILD)/,$(SRCS:.c=.o))


all: clean mkdirs $(COBJS)


mkdirs:
	$(shell mkdir ${BUILD})


$(COBJS): $(BUILD)/%.o : %.c
	$(CC) $< -o $@



server:
	$(CC) -o hello_server hello_server.c

client:
	$(CC) -o tcp_client tcp_client.c


clean:
	rm -rf $(BUILD)
	rm -rf hello_server
	rm -rf tcp_client


	


