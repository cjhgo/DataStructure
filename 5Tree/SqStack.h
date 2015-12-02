#ifndef SQSTCAK_H
#define SQSTCAK_H

#define INIT_SIZE 100
#define INCREMENT 10


template <typename T>
class SqStack
{
public:
	SqStack();
	~SqStack();

	Status Push(T e);
	Status Pop(T& e);
	Status Top(T& e);
	bool Is_Empty();
private:
	T* base;
	T* top;
	int length;
	int stacksize;
};

#include "SqStack.cpp"
#endif