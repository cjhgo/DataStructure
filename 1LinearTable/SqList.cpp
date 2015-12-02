#include "head.h"
#include "SqList.h"

Status InitList_Sq(SqList &L)
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));		
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
Status ListInsert_Sq(SqList& L,int i,ElemType e)
{
	//第一步:判断插入的位置是否合法,
	if(i < 1 || i > (L.length + 1))
		return ERROR;
	//第二步:判断是否还有剩余空间
	
	if( L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
		
	
	

	ElemType * q = &(L.elem[i-1]);
	for(ElemType* p = &(L.elem[L.length - 1]);p >= q;p--)
		*(p+1) = *p;
	*q = e;
	L.length++;
	return OK;
}
Status ListDelete_Sq(SqList& L,int i,ElemType& e)
{
	if(i < 1 || i > L.length) return ERROR;
	ElemType* q = &(L.elem[i-1]);
	e = *q;
	ElemType* p = &(L.elem[L.length-1]);
	for(;q < p;q++)
		*q = *(q+1);
	L.length--;
	return OK;
}
void ShowList_Sq(SqList& L)
{
	printf("------show sqlist------\n");
	printf("L.length: %d\n",L.length);
	for(int i = 0;i < L.length;i++)
		printf("%d:\t%d\n",i,L.elem[i]);
}