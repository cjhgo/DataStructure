#include "head.h"
#include "BTree.h"


int main(int argc, char const *argv[])
{
	BTree<char> mybtree;
	mybtree.InitWithPreorder_Re(mybtree.root);

	// mybtree.InitWithPreorder_Re(mybtree.root);
	mybtree.Preorder_NRe();
	
	cout<<"-----------------------\n";
	mybtree.Inorder_NRe();	

	cout<<"-----------------------\n";
	// mybtree.Postorder_NRe();	

	return 0;
}



/**
*test template stack
#include "SqStack.h"
SqStack<int> mystack;
		mystack.Push(5);
		int x = 3;
		cout<<x<<endl;
		mystack.Top(x);
	mystack.Push(99);
	mystack.Pop(x);
	cout<<x<<endl;
	if(mystack.Is_Empty())
		cout<<"Is_Empty"<<endl;
	else
		cout<<"not_empty";
	mystack.Pop(x);
	cout<<x<<endl;
	if(mystack.Is_Empty())
		cout<<"Is_Empty"<<endl;
	else
		cout<<"not_empty";

**/
