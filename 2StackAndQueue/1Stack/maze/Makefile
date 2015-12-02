CC=g++
CFLAGS += -Wall -g  -std=c++11
solve_maze:main.o Stack.o Maze.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
Stack.o:Stack.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
Maze.o:Maze.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@	
clean:
	del *.o