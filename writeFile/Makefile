#Compiler
CC = gcc

#Target
TARGET = writeFile

CFLAGS = -Wall

#Exe
build: object
	$(CC) $(CFLAGS) $(TARGET).o -o $(TARGET).out
debug: object
	$(CC) $(CFLAGS) -g $(TARGET).o -o $(TARGET).out
object: $(TARGET).c
	$(CC) $(CFLAGS) -g -c $(TARGET).c
buildThread:
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET).out -lpthread

clean:
	rm -rf *.o *.out
