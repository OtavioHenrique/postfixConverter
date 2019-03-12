HEADERS = lib/stack.h
BIN_NAME=postfix-converter
CC=gcc

default: program

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

program: $(OBJECTS)
	$(CC) postfix.c $(OBJECTS) -o $(BIN_NAME)

clean:
	-rm -f $(OBJECTS)
	-rm -f program
