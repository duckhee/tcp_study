CC = gcc

TARGET = 

SRCS = low_open.c low_read.c

BUILD = build

COBJS = $(addprefix $(BUILD)/,$(SRSC:.c=.o))

$(COBJS): $(BUILD)/%.o: %.c
	$(CC) $< -o $@

mkdirs:
	$(shell mkdir ${BUILD})

all: mkdirs


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



