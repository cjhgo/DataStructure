#ifndef SQSTCAK_H
#define SQSTCAK_H

typedef struct SqStack
{
	ElemType* base;
	ElemType* top;
	int length;
	int stacksize;
}SqStack;
Status InitStack(SqStack& stack);
Status Stack_Push(SqStack& stack,ElemType e);
Status Stack_Pop(SqStack& stack,ElemType& e);
Status Stack_Top(SqStack& stack,ElemType& e);
bool Stack_Empty(SqStack& stack);
#endif