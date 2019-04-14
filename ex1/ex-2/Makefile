CC = gcc

TARGET = 

SRCS = low_open.c low_read.c fd_seri.c

BUILD = build

COBJS = $(addprefix $(BUILD)/,$(SRCS:.c=.o))

all: clean mkdirs $(COBJS)


mkdirs:
	$(shell mkdir ${BUILD})


$(COBJS): $(BUILD)/%.o: %.c
	$(CC) $< -o $@


open:
	gcc -o low_open low_open.c

read:
	gcc -o low_read low_read.c

seri:
	$(CC) -o fd_seri fd_seri.c

clean:
	rm -rf build
	rm -f low_open
	rm -f low_read
	rm -f data.txt
	rm -f fd_seri
	rm -f test.dat



