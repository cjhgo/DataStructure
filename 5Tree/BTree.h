#ifndef BTREE_H
#define BTREE_H
#include "head.h"

#include "SqStack.h"

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
	Node* parent;

};

template <typename T>
using NodePtr =Node<T>*;
//typedef Node<T>* NodePtr;

template <typename T>
class BTree
{
public:
	// BTree(T data);
	BTree();
	~BTree();
	Status InitWithPreorder_Re(NodePtr<T>& node);
	Status Preorder_Re(NodePtr<T> root);
	Status InitWithPreorder_NRe(NodePtr<T>& node);
	Status Preorder_NRe();
	Status Inorder_NRe();	
	Status Postorder_NRe();	

	// NodePtr FindPos(int i);
	// Status Repalce(int i,T data);
	// Status Insert(T data);
// private:	
	NodePtr<T> root;
	int NodeNumber;
};

#include "BTree.cpp"
#endif