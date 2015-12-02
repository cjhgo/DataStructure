#include "head.h"
#include "LinkedList.h"


Status InitList_L(LinkedList& L)
{
	L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;

	return OK;
}
/*0<= i <= N*/
LinkedList GetElemP_L(LinkedList L,int k)
{
	LNode * p = L;
	int j = 0;
	while(p && j < k)
	{
		p = p->next;
		j++;
	}
	/*
	*p为空,没找到
	*j > k,说明k<0,不在正确范围内,也返回错误
	*/
	if( !p || j > k)
		return NULL;
	return p;
}
/* should: 1<= i <= N*/
Status GetElem_L(LinkedList L,int i,ElemType &e)
{
	// LNode * p = L->next;
	// int j = 1;
	// while(p && j < i)
	// {
	// 	p = p->next;
	// 	j++;
	// }
	// if(!p || j > i)
	// 	return ERROR;

	LNode * p = GetElemP_L(L,i);

	if( p == L || !p)return ERROR;

	e = p->data;
	return OK;
}
/* should : 1<= i <= N+1*/
Status ListInsert_L(LinkedList L,int i,ElemType e)
{
	// LinkedList p = L;
	// int j = 0;

	// while(p && j < i-1)
	// {
	// 	p = p->next;
	// 	j++;
	// }
	// if( !p || j > i-1)
	// 	return ERROR;
	LinkedList p = GetElemP_L(L,i-1);
	if(!p) return ERROR;
	LNode* s = (LinkedList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}
Status ListDelete_L(LinkedList L,int i,ElemType& e)
{
	// LinkedList p = L;
	// int j = 0;
	// while(p->next && j < i-1)
	// {
	// 	p = p->next;
	// 	j++;
	// }
	// if(!(p->next) || j > i-1)
	// 	return ERROR;
	LinkedList p = GetElemP_L(L,i-1);
	if(!p) return ERROR;
	
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;

	free(q);

	return OK;
}
void ShowList_L(LinkedList &L)
{
	LNode * p = L->next;
	int i = 1;
	while(p!= NULL)
	{
		cout<<i<<":\t"<<p->data<<endl;
		p = p->next;
		i++;
	}
}