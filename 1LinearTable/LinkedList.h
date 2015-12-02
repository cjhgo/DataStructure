#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LNode
{
	ElemType data;
	LNode * next;
}*LinkedList;

Status InitList_L(LinkedList& L);
Status GetElem_L(LinkedList L,int i,ElemType &e);
LinkedList GetElemP_L(LinkedList L,int i);
Status ListInsert_L(LinkedList L,int i,ElemType e);
Status ListDelete_L(LinkedList L,int i,ElemType& e);
void ShowList_L(LinkedList &L);
#endif