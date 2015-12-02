#include "head.h"
#include "SqStack.h"

Status InitStack(SqStack& stack)
{
	stack.base = (ElemType*)malloc(INIT_SIZE*sizeof(ElemType));
	stack.top = stack.base;
	stack.length = 0;
	stack.stacksize = INIT_SIZE;

	return OK;
}
Status Stack_Push(SqStack& stack,ElemType e)
{
	if(stack.base + stack.stacksize == stack.top)
	{
		ElemType* newbase = (ElemType*)realloc(stack.base,(stack.stacksize + INCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		stack.base = newbase;		
		stack.top = stack.base + stack.stacksize;
		stack.stacksize += INCREMENT;
	}
	*(stack.top) = e;
	stack.top++;

	return OK;
}
Status Stack_Pop(SqStack& stack,ElemType& e)
{
	if(stack.top == stack.base)
		return ERROR;

	stack.top--;
	e = *(stack.top);

	return OK;
}
Status Stack_Top(SqStack& stack,ElemType& e)
{
	if(stack.top == stack.base)
		return ERROR;
	
	e = *(stack.top-1);
	
	return OK;
}
bool Stack_Empty(SqStack& stack)
{
	if(stack.base == stack.top)
		return true;
	else
		return false;	
}