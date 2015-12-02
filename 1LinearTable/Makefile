CC=g++
CFLAGS += -Wall -g
test:main.o SqList.o LinkedList.o DuLinkedList.o Polynomial.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
SqList.o:SqList.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
LinkedList.o:LinkedList.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@	
DuLinkedList.o:DuLinkedList.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@		
Polynomial.o:Polynomial.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@			
clean:
	rm *.o