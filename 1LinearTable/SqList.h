#ifndef SQLIST_H
#define SQLIST_H

typedef struct 
{
	ElemType* elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList& L,int i,ElemType e);
Status ListDelete_Sq(SqList& L,int i,ElemType& e);
void   ShowList_Sq(SqList& L);
#endif