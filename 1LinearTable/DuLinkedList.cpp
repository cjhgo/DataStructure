#include "head.h"
#include "DuLinkedList.h"

Status InitList_DuL(DuLinkedList& L)
{
	L=(DuLNode *)malloc(sizeof(DuLNode));
	L->next = L;
	L->prior = L;

	return OK;
}	

/*0<= i <= N*/
DuLinkedList GetElemP_DuL(DuLinkedList L,int i)
{
	//why this line ,,,,,
	//没有这一行,L为空&向i=1处插入时,没有返回头结点,返回了空指针
	if( i == 0) return L;

	/*
	*DuLinkedList p = L;
	*int j = 0;
	*/
	DuLinkedList p = L->next;
	int j = 1;

	while(p != L && j < i)
	{
		p = p->next;
		j++;
	}	
	/*i < 0:j>i
	* i > N:p == L
	*/
	if(p == L || j > i) return NULL;
	return p;
}


/*1<= i <= N
*1:first
*N:last
*head or NULL is wrong
*/
Status GetElem_DuL(DuLinkedList L,int i,ElemType &e)
{
	DuLinkedList p = GetElemP_DuL(L,i);
	if(p == L || !p) return ERROR;
	e = p->data;
	return OK;
}

/*1<= i <= N+1*/
/*0<= i-1 <= N*/
Status ListInsert_DuL(DuLinkedList L,int i,ElemType e)
{
	DuLinkedList p = GetElemP_DuL(L,i-1);
	if(p == NULL) return ERROR;
	DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
	s->data = e;

	
	p->next->prior = s;
	s->next = p->next;
	p->next = s;
	s->prior = p;

	return OK;
}

/*1<= i <= N
*1:first
*N:last
*head or NULL is wrong
*/
Status ListDelete_DuL(DuLinkedList L,int i,ElemType& e)
{
	DuLinkedList p = GetElemP_DuL(L,i);

	if(p == L || !p) return ERROR;

	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	return OK;
}
void ShowList_DuL(DuLinkedList &L)
{
	DuLinkedList p = L->next;
	int i = 1;
	while(p != L)
	{
		cout<<i<<":\t"<<p->data<<endl;
		p = p->next;
		i++;
	}
}