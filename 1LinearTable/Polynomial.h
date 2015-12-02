#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
typedef struct Term
{
	double p;
	int e;
	Term *next;
}* Poly;

Status CreatePoly(Poly& poly,int m);
Status InitList_Poly(Poly& L);
Poly GetElemP_Poly(Poly L,int i);
Status ListInsert_Poly(Poly L,int i,int p ,int e);
Status ListInsert_Poly(Poly L,int i,Term* insp);
Status ListDelete_Poly(Poly L,int i);
void AddPoly(Poly& pa ,Poly& pb);
void AddPoly_v2(Poly& pa ,Poly& pb);
void SubPoly(Poly& pa ,Poly& pb);
void ShowList_Poly(Poly &L);
#endif 