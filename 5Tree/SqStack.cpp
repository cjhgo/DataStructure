template<typename T>
SqStack<T>::SqStack()
{
	this->base = (T*)malloc(INIT_SIZE*sizeof(T));
	this->top = this->base;
	this->length = 0;
	this->stacksize = INIT_SIZE;
}

template<typename T>
SqStack<T>::~SqStack()
{
	
}

template<typename T>
Status SqStack<T>::Push(T e)
{
	if(this->base + this->stacksize == this->top)
	{
		T* newbase = (T*)realloc(this->base,(this->stacksize + INCREMENT)*sizeof(T));
		if(!newbase) exit(OVERFLOW);
		this->base = newbase;		
		this->top = this->base + this->stacksize;
		this->stacksize += INCREMENT;
	}
	*(this->top) = e;
	this->top++;

	return OK;
}

template<typename T>
Status SqStack<T>::Pop(T& e)
{
	if(this->top == this->base)
		return ERROR;

	this->top--;
	e = *(this->top);

	return OK;
}

template<typename T>
Status SqStack<T>::Top(T& e)
{
	if(this->top == this->base)
		return ERROR;
	
	e = *(this->top-1);
	
	return OK;
}

template<typename T>
bool SqStack<T>::Is_Empty()
{
	if(this->base == this->top)
		return true;
	else
		return false;	
}