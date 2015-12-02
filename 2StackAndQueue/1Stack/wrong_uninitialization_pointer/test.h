void conversion()
{
	cout<<"this is a function tha convert decimal to octal with a stack\n";
	int number_to_convert = -1;
	cout<<"input the number to be converted\n";
	cin>>number_to_convert;

	SqStack mystack;
	InitStack(mystack);

	// while(number_to_convert / 8)
	// {
	// 	Stack_Push(mystack,number_to_convert % 8);
	// 	number_to_convert /= 8;
	// }
	// Stack_Push(mystack,number_to_convert);

	while(number_to_convert)
	{
		Stack_Push(mystack,number_to_convert % 8);
		number_to_convert /= 8;
	}

	int digit = -1;
	while(Stack_Pop(mystack,digit) == OK)
	{
		cout<<digit;
	}
	cout<<"\n---done----"<<endl;
}
void parenthesesmatch()
{
	
	SqStack mystack;
	InitStack(mystack);
	cout<<"this is a function for parentheses matching\n";
	cout<<"input the string of the parentheses,end with the #\n";
	char parentheses;	
	while(cin>>parentheses)
	{
		if(parentheses == '#')
			break;
		int number = 0;
		switch(parentheses)
		{
			case '(':number = 1;break;
			case ')':number = -1;break;
			case '[':number = 2;break;
			case ']':number = -2;break;
			case '{':number = 3;break;
			case '}':number = -3;break;
			default:cout<<"wrong input,now exit\n";return;
		}
		if(number > 0)
		{
			Stack_Push(mystack,number);
		}
		else if(number < 0)
		{
			int topnumber = 0;
			Stack_Top(mystack,topnumber);
			if(number + topnumber == 0)
			{
				Stack_Pop(mystack,topnumber);
			}
			else
			{
				cout<<"not matched......\n";
				return;
			}
		}
	}
	if(Stack_Empty(mystack))
		cout<<"\n^_^,it is good\n";
	else 
		cout<<"\nnot matched.........\n";

}