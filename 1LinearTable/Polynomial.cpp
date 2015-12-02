#include "head.h"
#include "Polynomial.h"


Status CreatePoly(Poly& poly,int m)
{
	InitList_Poly(poly);
	for(int i = 0;i < m;i++)
	{
		double p;
		int e;

		cout<<"input the value of p & e,"<<i+1<<":\n";
		cin>>p>>e;
		ListInsert_Poly(poly,i+1,p,e);
	}
	cout<<"now ,the poly is as below\n";
	ShowList_Poly(poly);

	return ERROR;
}
Status InitList_Poly(Poly& L)
{
	L = (Poly)malloc(sizeof(Term));
	L->next = NULL;

	return OK;
}
/*0<= i <= N*/
Poly GetElemP_Poly(Poly L,int k)
{
	Term * p = L;
	int j = 0;
	while(p && j < k)
	{
		p = p->next;
		j++;
	}
	if( !p || j > k)
		return NULL;
	return p;
}

/* should : 1<= i <= N+1*/
Status ListInsert_Poly(Poly L,int i,int p,int e)
{	
	Poly polyi_1 = GetElemP_Poly(L,i-1);
	if(!p) return ERROR;
	Term* s = (Poly)malloc(sizeof(Term));
	s->p = p;
	s->e = e;	
	s->next = polyi_1->next;
	polyi_1->next = s;

	return OK;
}
Status ListInsert_Poly(Poly L,int i,Term* insp)
{
	Poly polyi_1 = GetElemP_Poly(L,i-1);
	if(!polyi_1) return ERROR;	

	insp->next = polyi_1->next;
	polyi_1->next = insp;

	return OK;	
}
Status ListDelete_Poly(Poly L,int i)
{	
	Poly p = GetElemP_Poly(L,i-1);
	if(!p) return ERROR;
	
	Term* q = p->next;
	p->next = q->next;

	free(q);

	return OK;
}
/*
*pa = pa + pb
*
*/
void AddPoly(Poly& pa ,Poly& pb)
{
	Term* indpa = pa->next;
	Term* indpb = pb->next;
	int posa = 1;
	int posb = 1;

	while(indpa && indpb)
	{
		if( indpa->e < indpb->e)
		{
			indpa = indpa->next;
			posa++;
		}
		else if( indpa->e == indpb->e)
		{
			int temp = indpa->p + indpb->p;
			if(temp == 0)
			{				
				indpa = indpa->next;
				ListDelete_Poly(pa,posa);

				indpb = indpb->next;
				ListDelete_Poly(pb,posb);				
			}
			else
			{
				indpa->p = temp;

				indpa = indpa->next;
				posa++;

				indpb = indpb->next;
				ListDelete_Poly(pb,posb);
			}
		}
		else if( indpa->e > indpb->e)
		{
			Term* indpb_prior = GetElemP_Poly(pb,posb-1);
			indpb_prior->next = indpb->next;

			ListInsert_Poly(pa,posa,indpb);
			posa++;

			indpb = indpb_prior->next;

		}
	}
	// if(indpa)
	{

	}
	if(indpb)
	{
		// cout<<"cjh!!!!!!!!!!\n";
		// cout<<indpb->p<<TAB<<indpb->e<<endl;
		// cout<<"cjh!!!!!!!!!!\n";

		Term* lastpa = GetElemP_Poly(pa,posa-1);
		Term* indpb_prior = GetElemP_Poly(pb,posb-1);
		indpb_prior->next = NULL;
		lastpa->next = indpb;
	}
}
void AddPoly_v2(Poly& La ,Poly& Lb)
{
	Poly pc = La;
	Term* pa = La->next;
	Term* pb = Lb->next;
	while(pa && pb)
	{
		if(pa->e < pb->e)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if(pa->e == pb->e)
		{
			if((pa->p + pb->p) == 0)
			{
				Term* temp = NULL;
				temp = pa;
				pa = pa->next;
				free(temp);

				temp = pb;
				pb = pb->next;
				free(temp);

				temp = NULL;
			}
			else 
			{
				pa->p = pa->p + pb->p;
				pc->next = pa;
				pc = pa;
				pa = pa->next;

				Term* temp = pb;
				pb = pb->next;
				free(temp);
				temp = NULL;
			}
		}
		else if( pa->e > pb->e)
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
}
/*
*pa = pa - pb
*
*/
void SubPoly(Poly& pa ,Poly& pb)
{

}
void ShowList_Poly(Poly &L)
{

	Term * p = L->next;
	int i = 1;
	cout<<"------begin of poly-----\n";
	while(p!= NULL)
	{
		cout<<i<<":\t"<<p->p<<TAB<<p->e<<endl;
		p = p->next;
		i++;
	}
	cout<<"------end of poly-----\n";
	cout<<endl<<endl<<endl;
}