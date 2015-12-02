#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

typedef struct LQueueNode
{
	ElemType data;
	LQueueNode* next;
}LQueueNode,*LQueueNodePtr;
typedef struct LQueue
{
	LQueueNodePtr front;
	LQueueNodePtr rear;
}LQueue,*LQueuePtr;

Status InitQueue_L(LQueue& head);
Status EnQueue_L(LQueue head,ElemType e);
Status DeQueue_L(LQueue head,ElemType& e);

#endif