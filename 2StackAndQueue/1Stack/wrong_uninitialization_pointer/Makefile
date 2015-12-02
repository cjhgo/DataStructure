CC=g++
CFLAGS += -Wall -g
test:main.o Stack.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
Stack.o:Stack.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
clean:
	rm *.o