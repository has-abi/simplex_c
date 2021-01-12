CC=gcc
CFLAGS=-c
LDFLAGS=-lm
EXEC=exe
SRC=$(wildcard *c)
OBJ=$(SRC:.c=.o)
$(EXEC):$(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 
%.o:%.c
	$(CC) $(CFLAGS) $<
clean:
	rm -r *.o

