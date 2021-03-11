#Compiler
CC = gcc

#Target
TARGET = ...

CFLAGS = -Wall

#Exe
build: object
	$(CC) $(CFLAGS) $(TARGET).o -o $(TARGET).out
debug: object
	$(CC) $(CFLAGS) -g $(TARGET).o -o $(TARGET).out
object: $(TARGET).c
	$(CC) $(CFLAGS) -g -c $(TARGET).c

clean:
	rm -rf *.o *.out
