CC=g++
CFLAGS += -Wall -g -std=c++11
test:main.o LinkedQueue.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
LinkedQueue.o:LinkedQueue.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
SqQueue.o:SqQueue.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@	
clean:
	rm *.o