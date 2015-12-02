CC=g++
CFLAGS += -Wall -g
TARGET=InsertSort.o BInsertSort.o QuickSort.o SelectSort.o
#TPInsertSort.o ShellSort.o BubbleSort.o  
test:main.o Reader.o $(TARGET) 
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
Reader.o:Reader.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@	
InsertSort.o:InsertSort.cpp 
	$(CC)  -c $(CFLAGS) $^ -o $@	
BInsertSort.o:BInsertSort.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
# TPInsertSort.o:TPInsertSort.cpp
# 	$(CC)  -c $(CFLAGS) $^ -o $@
# ShellSort.o:ShellSort.cpp
# 	$(CC)  -c $(CFLAGS) $^ -o $@		
# BubbleSort.o:BubbleSort.cpp
# 	$(CC)  -c $(CFLAGS) $^ -o $@
QuickSort.o:QuickSort.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
SelectSort.o:SelectSort.cpp
	$(CC)  -c $(CFLAGS) $^ -o $@
clean:
	rm *.o