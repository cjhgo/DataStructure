CC=g++
CFLAGS += -Wall -g -std=c++11
test:main.o 
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
clean:
	rm *.o