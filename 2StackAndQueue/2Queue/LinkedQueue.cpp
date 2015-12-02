#include "head.h"
#include "LinkedQueue.h"

Status InitQueue_L(LQueue& queue)
{
	queue.front=queue.rear=(LQueueNodePtr)malloc(sizeof(LQueueNode));

	queue.front->next = NULL;

	return OK;
}
Status EnQueue_L(LQueue queue,ElemType e)
{
	LQueueNodePtr p = (LQueueNodePtr)malloc(sizeof(LQueueNode));

	if(!p) exit(OVERFLOW);

	p->data = e;
	p->next = NULL;
	queue->rear->next = p;
	queue->rear = p;

	return OK:
}
Status DeQueue_L(LQueue queue,ElemType& e)
{
	if(queue.front == queue.rear) return ERROR;

	LQueueNodePtr p = queue.front->next;

	e = p->data;
	queue.front->next = p->next;

	if(queue.rear == p) queue.rear = queue.front;
	free(p);

	return OK:
}