SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o
	$(CC) $(CFLAGS) -o $@ $<

client: client.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean
