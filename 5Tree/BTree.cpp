
template <typename T>
BTree<T>::BTree()
{
	this->root = new Node<T>;
	this->root->data = 0;
	this->root->parent = NULL;
	this->root->left=root->right=NULL;
	this->NodeNumber = 1;
}
template <typename T>
BTree<T>::~BTree()
{

}

template <typename T>
Status BTree<T>::InitWithPreorder_Re(NodePtr<T>& node)
{
	T data;
	cin>>data;
	if(data == '#')
		return OK;
	else
	{
		if(node == NULL)
		{
			node = new Node<T>;
			node->left = NULL;
			node->right = NULL;
		}
		node->data = data;
		this->InitWithPreorder_Re(node->left);
		this->InitWithPreorder_Re(node->right);
	}
}
template <typename T>
Status BTree<T>::Preorder_Re(NodePtr<T> root)
{
	if(root == NULL)
		return OK;
	else
		cout<<root->data<<endl;
	Preorder_Re(root->left);
	Preorder_Re(root->right);

}

template <typename T>
Status BTree<T>::InitWithPreorder_NRe(NodePtr<T>& node)
{

}
template <typename T>
Status BTree<T>::Preorder_NRe()
{
	SqStack<Node<T>> stack;
	NodePtr<T> cur = this->root;

	
	do	
	{
		while(cur)
		{
			stack.Push(*cur);
			cout<<cur->data<<endl;
			cur = cur->left;
		}
		if(!stack.Is_Empty())
		{
			Node<T> temp;
			stack.Pop(temp);
			cur = temp.right;
		}

	}
	while(!stack.Is_Empty());
}

template <typename T>
Status BTree<T>::Inorder_NRe()
{
	SqStack<Node<T>> stack;
	NodePtr<T> cur = this->root;

	
	do	
	{
		while(cur)
		{
			stack.Push(*cur);
			cur = cur->left;
		}
		if(!stack.Is_Empty())
		{
			Node<T> temp;

			stack.Pop(temp);
			cout<<temp.data<<endl;		

			cur = temp.right;

			//stack.Pop(temp);
			//cout<<temp.data<<endl;		

		}

	}
	while(!stack.Is_Empty());
}

template <typename T>
Status BTree<T>::Postorder_NRe()
{
	SqStack<Node<T>> stack;
	NodePtr<T> cur = this->root;

	
	do	
	{
		while(cur)
		{
			stack.Push(*cur);
			cur = cur->left;
		}
		if(!stack.Is_Empty())
		{
			Node<T> temp;

			stack.Top(temp);

			if(temp.right)
			{
				// stack.Push(*temp.right);
				cur = temp.right;
			}
			else
			{
				stack.Pop(temp);
				cout<<temp.data<<endl;

				stack.Top(temp);
				cur = temp.right;

			}

			//stack.Pop(temp);
			//cout<<temp.data<<endl;		

		}

	}
	while(!stack.Is_Empty());
}


/*
Node<T> top;
		stack.Top(top);
		cout<<top.data<<endl;

		Node<T> root = top;
		do
		{
			if(top.left)
			{
				stack.Push(*top.left);
				stack.Top(top);
				cout<<top.data<<endl;
			}
			else
			{
				if(top.right)
				{
					stack.Push(*top.right);
					stack.Top(top);
					cout<<top.data<<endl;
				}
				else
				{
					stack.Pop(top);
					stack.Top(top);
				}
			}

		}
		while(top != root)

		if(top.right)
		{
			stack.Push(*top.right);
		}
		else
			
		

*/