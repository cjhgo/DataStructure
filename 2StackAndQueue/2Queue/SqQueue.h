#ifndef SQQUEUE_H
#define SQQUEUE_H

#define MAX_SIZE 100+1

typedef struct SqQueue 
{
	ElemType* base;
	int front;
	int rear;
}SqQueue;

Status InitQueue_Sq(SqQueue& queue);
Status EnQueue_Sq(SqQueue queue,ElemType e);
Status DeQueue_Sq(SqQueue queue,ElemType& e);
int QueueLength(SqQueue queue);
#endif 