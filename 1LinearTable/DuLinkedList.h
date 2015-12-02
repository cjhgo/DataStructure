#ifndef DULINKEDLIST_H
#define DULINKEDLIST_H
typedef struct DuLNode
{
	ElemType data;
	DuLNode * next;
	DuLNode * prior;
}* DuLinkedList;



Status InitList_DuL(DuLinkedList& L);
DuLinkedList GetElemP_DuL(DuLinkedList L,int i);
Status GetElem_DuL(DuLinkedList L,int i,ElemType &e);
Status ListInsert_DuL(DuLinkedList L,int i,ElemType e);
Status ListDelete_DuL(DuLinkedList L,int i,ElemType& e);
void ShowList_DuL(DuLinkedList &L);
#endif