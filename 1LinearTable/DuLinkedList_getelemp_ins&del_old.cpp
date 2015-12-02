/* 0<= i <= N+1
*0:head
*N+1:head
*/
DuLinkedList GetElemP_DuL(DuLinkedList L,int i)
{
	if( i== 0)return L;
	DuLinkedList p = L->next;
	/*
	*2015-8-11:L有可能是个空的,,,,这时,p=L,,,,,
	*/
	if(p == L ) return NULL;

	/*j=1,意即p指向第一个结点,
	*自然暗示了L非空的前提,,,
	*所以之前一定要对L为空进行处理,,,
	*/
	int j = 1;


	/*
	*p从第一个结点开始,向后遍历
	*j是p指向的结点的位序
	*指向第i个结点时停止,此时j==i,
	*或者指向了头结点,遍历结束,也停止
	*/
	while(p != L && j < i)
	{
		p = p->next;
		j++;
	}
	//i < 0
	if(p != L && j > i ) return NULL;
	
	//if(p != L && j == i) what we nedd

	if(p == L)
	{

		//if(j > i) it is impossible

		// i = N+1
		if(j == i) return L;
		
		//i > N+1 
		if(j < i) return NULL;
	}
	
	return p;
}

/*i:1-N+1*/
Status ListInsert_DuL(DuLinkedList L,int i,ElemType e)
{
	if(i == 0) return ERROR;


	DuLinkedList p = GetElemP_DuL(L,i);



	/*
	*2015-08-11修改,i=0时,p指向头结点,这也是不允许的
	*if(!p) return ERROR;
	*
	*if(p == L || !p) return ERROR;
	*2015-8-11再次修改,.....上个修改是错的,因为当i=N+1的时候,p=L,是符合要求的,,,,
	*所以只能,对i=0单独出错处理了,,,,
	*/

	if(p == L || !p) return ERROR;
	DuLNode* s = (DuLinkedList)malloc(sizeof(DuLNode));
	s->data = e;

	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}
/*i:1-N*/
Status ListDelete_DuL(DuLinkedList L,int i,ElemType& e)
{
	DuLinkedList p = GetElemP_DuL(L,i);

	if(!p) return ERROR;

	p->prior->next = p->next;
	p->next->prior = p->prior;
	e = p->data;
	free(p);
	return OK;
}