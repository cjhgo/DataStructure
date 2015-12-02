#ifndef STCAK_H
#define STCAK_H

typedef struct Stack
{
	ElemType* base;
	ElemType* top;
	int length;
	int stacksize;
}Stack,*SqStack;
Status InitStack(SqStack& stack);
Status Stack_Push(SqStack stack,ElemType e);
Status Stack_Pop(SqStack stack,ElemType& e);
Status Stack_Top(SqStack stack,ElemType& e);
bool Stack_Empty(SqStack stack);
void Show_ElemType(ElemType e);
void Show_Stack(SqStack stack);
#endif