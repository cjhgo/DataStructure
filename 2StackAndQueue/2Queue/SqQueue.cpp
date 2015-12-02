#include "head.h"
#include "SqQueue.h"

Status InitQueue_Sq(SqQueue& queue)
{
	queue.base  = (ElemType*)malloc(MAX_SIZE*sizeof(ElemType));

	queue.front=queue.rear= 0;

	return OK;
}
Status EnQueue_Sq(SqQueue queue,ElemType e)
{
	if((queue.rear + 1)%MAX_SIZE == queue.front)
		exit(OVERFLOW);

	queue.base[rear] = e;
	queue.rear = (queue.rear + 1)%MAX_SIZE;

	return OK;
}
Status DeQueue_Sq(SqQueue queue,ElemType& e)
{
	if(queue.rear == queue.front)
		return ERROR;

	e = queue.base[queue.front];

	queue.front = (queue.front + 1)%MAX_SIZE;

	return OK;
}

int QueueLength(SqQueue queue)
{
	return (MAX_SIZE + queue.rear - queue.front) % MAX_SIZE;
}