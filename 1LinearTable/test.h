void test_sqlist()
{
	SqList mysqlist;
	// fun();
	InitList_Sq(mysqlist);
	ShowList_Sq(mysqlist);
	Status res = ListInsert_Sq(mysqlist,1,4);
	if(res != OK)
		printf("insert has failed,,,,,\n");		
	ShowList_Sq(mysqlist);

	res = ListInsert_Sq(mysqlist,1,5);
	if(res != OK)
		printf("insert has failed,,,,,\n");		
	ShowList_Sq(mysqlist);


	res = ListInsert_Sq(mysqlist,3,8);
	if(res != OK)
		printf("insert has failed,,,,,\n");		
	ShowList_Sq(mysqlist);

	res = ListInsert_Sq(mysqlist,2,7);
	if(res != OK)
		printf("insert has failed,,,,,\n");		
	ShowList_Sq(mysqlist);
}
void test_linkedlist()
{
	LinkedList mylinkedlist;
	InitList_L(mylinkedlist);
	if(mylinkedlist->next == NULL)
		cout<<"it is good\n";
	int i = 1;
	for(;i < 6;i++)
	{
		// ListInsert_L(mylinkedlist,1,i*i);	
		ListInsert_L(mylinkedlist,i,i*i);			
	}
	ListInsert_L(mylinkedlist,i,999);

	ShowList_L(mylinkedlist);


	LinkedList q = GetElemP_L(mylinkedlist,3);
	cout<<"!:\t"<<q->data<<endl;
	int test = -1;
	GetElem_L(mylinkedlist,0,test);
	cout<<"test:\t"<<test<<endl;

	GetElem_L(mylinkedlist,2,test);
	cout<<"test,in pos 2:\t"<<test<<endl;

}
void test_dulinkedlist()
{
	DuLinkedList mydulinkedlist;
	InitList_DuL(mydulinkedlist);
	if(mydulinkedlist->next == mydulinkedlist)
		cout<<"after initialization,head->next point head,it is correct\n";
	int i = 1;
	for(;i < 6;i++)
	{
		// ListInsert_L(mydulinkedlist,1,i*i);	
		ListInsert_DuL(mydulinkedlist,i,i*i);			
	}
	ListInsert_DuL(mydulinkedlist,i,999);
	cout<<"insert some data(6) into mydulinkedlist\n";

	ShowList_DuL(mydulinkedlist);

	// int j  = -1;
	cout<<"get the node  at pos 6:";	
	DuLinkedList q = GetElemP_DuL(mydulinkedlist,6);
	cout<<q->data<<endl;

	cout<<"insert data at pos N+1"<<endl;
	ListInsert_DuL(mydulinkedlist,7,1024);
	ShowList_DuL(mydulinkedlist);
	cout<<"show the value of the node before q:(25)\t";
	cout<<q->prior->data<<endl;	
}
void test_polynomial()
{
	Poly pa;
	Poly pb;
	CreatePoly(pa,4);
	CreatePoly(pb,5);
	// AddPoly(pa,pb);
	AddPoly_v2(pa,pb);
	ShowList_Poly(pa);
	// ShowList_Poly(pb);
}