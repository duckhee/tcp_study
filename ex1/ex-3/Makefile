CC = gcc

TARGET = 

SRCS = hello_server.c

BUILD = build



mkdirs:
	$(shell mkdir ${BUILD})


COBJS = $(addprefix $(BUILD)/,$(SRCS:.c=.o))

$(COBJS): $(BUILD)/%.o : %.c
	$(CC) $< -o $@



all: mkdirs


server:
	$(CC) -o hello_server hello_server.c

client:
	$(CC) -o tcp_client tcp_client.c


clean:
	rm -rf $(BUILD)
	rm -rf hello_server
	rm -rf tcp_client


	


