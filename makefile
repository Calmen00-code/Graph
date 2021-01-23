CC = gcc
CFLAGS = -Werror -Wall -pedantic -ansi -g
OBJ = Graph.o LinkedList.o GraphTest.o print.o stack.o queue.o
EXEC = graph

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

GraphTest.o : GraphTest.c Graph.h print.h header.h
	$(CC) $(CFLAGS) -c GraphTest.c

Graph.o : Graph.c Graph.h stack.h queue.h header.h
	$(CC) $(CFLAGS) -c Graph.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

print.o : print.c print.h
	$(CC) $(CFLAGS) -c print.c

stack.o : stack.c stack.h header.h
	$(CC) $(CFLAGS) -c stack.c

queue.o : queue.c queue.h header.h
	$(CC) $(CFLAGS) -c queue.c

clean: 
	rm -f $(OBJ) $(EXEC) 
