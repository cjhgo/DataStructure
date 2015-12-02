###数据结构是如何描述的
如何描述一个数据结构,
如何描述一个栈,?
如何描述一个队列,?
如何定义一个"树",?
脑子里有一个笼统的感觉是不够的,
从***集合论***的角度,定义数据结构
一个三元组,
(D,S,P)
(数据对象,数据关系,基本操作)

表的长度:表长为0就是空表,
插入的位置:1~N+1
0的意义,,!!
###顺序表的插入
***第i个数据元素是L.elem[i-1]***

+ 判断插入的位置i是否在1~N+1之间
+ 判断当前是否有空间以供插入
+ 获取插入的位置L.elem[i-1]
+ 把L.elem[i-1]~L.elem[N-1]之间的元素后移一位
+ L.elem[i-1]赋值
###链表的插入
***第i个结点就是从头结点后的第i个结点,头结点算第0个结点***

+ 获取插入的位置i之前的那个结点,即第i-1个结点
+ 根据上一步的情况,判断插入位置i的值是否合法:在1~N+1之间
+ 修改指针
#####顺序表和链表插入的比较
+ 顺序表存取第i个数据元素很容易,主要操作在于移动数据
+ 链表的主要操作在于获取第i个元素的位置,无论是插入,删除都依赖于找到位置,
+ 由于顺序表的长度是显式的,所以对于位置i可以直接判断是否合法
+ 由于链表的长度是隐含的,所以对于位置i无法直接判断是否合法,要在获取第i个结点的同时,判断结点指针是否是空指针
+ 在位置i处插入一个数据是指:在第i个数据元素之前插入一个元素(如果i的值是N+1,那么是把元素放在(顺序/链)表的尾部)
+ 同样是再位置i处插入一个元素
	+ 顺序表的插入是找到第i个数据元素,移动
	+ 链表的插入是找到第i-1个结点,修改指针
		- 第i-1个结点
			+ i=1:头结点
			+ i=j:第j-1个结点
			+ i=N+1:最后一个结点
#####头结点的引入	
**在位置i处插入一个数据,是把数据插入到第i个结点之前,用这样的插入来建立链表的话称之为***头插法***:每次插入一个数据都是放到头结点之前**
前边已经讲到,链表插入是找到插入位置之前的那个结点然后修改指针关系
可是当i=1,即在第一个结点前插入数据的时候,第一个结点前是不存在结点的
如果在第一个结点前也设置一个结点,那么后续的修改指针操作就完全一致,因此
引入了***头结点***
#####GetElem实现的细节
错误的实现
`
for(int j = 0;j < i;j++)
		p=p->next;
`		
合理的实现		p指向第i个元素或***为空***
`
while(p&&j<i)		
{
	p = p->next;
	j++;
}
`
####单链表和双向循环链表插入操作的不同之处
对于单链表的每个结点,只能访问它的下一个结点,而要想在在Node_i之前插入一个node,就要找到(Node_i-1)并修改它的next指针使之指向新结点,所以**insert(i,node)要找到(Node_i-1)**

而双向链表对每个结点,既能访问prior又能访问next,所以,要想在Node_i之前插入一个结点,就找到Node_i然后修改相关结点就可以了,所以**insert(i,node)就是找到(Node_i)**

+++++++++++可是这种思路在实践中([具体可参看这一段的描述](#n1))发现带来了很大的不方便,,,,主要就是i=N+1的时候,要返回head,+++++++
+++++++++++如果和单链表实现一样,i处插入,找到i-1处的位置,一切就又和谐了,getElemP的合法i值是0-N,对应于inser的合法i值是1-N+1,+++++++++++


####双向循环链表和双向非循环链表插入删除操作的不同,
是有很大的不同的!
插入或删除链表上的第i个结点时,
大致思路是:

+ 首先,找到第i个结点,Node_i
	- 然后修改这个结点的前一个结点的后向指针:next,和这个结点的后一个结点的前向指针:prior
+ 对于双向循环链表,根本不用考虑前后结点存不存在的问题,因为它是循环链表,***一定存在前后结点***,只有一个结点时,前后结点都是头结点,空的时候所有操作也都是一致的
+ 对于双向非循环链表,要***考虑前后结点是否存在的问题***,如果引入了头结点,那么每个结点的头结点都是存在的,但最后一个结点的后向结点为空,这就引起了操作的不一致性,在插入或删除时要额外注意,判断一下,,
###sum
实现链表的过程中,在一些细节的处理上能够很好地体现出一个程序员的编程技巧和思维能力。
细节主要体现在getposition函数中
插入元素,
删除元素,
存取元素
这3个基本操作都要依赖于获取某个结点的位置
对于单向链表,假如链表有N个结点,头结点算第0个结点
获取结点位置的合理位置值为0-N
插入结点的合理位置值为1-N+1
删除结点的合理位置值为1-N
存取结点的合理位置值为0-N
对于双向链表,由于既能访问prior又能访问next,和单链表稍有不同

***正确修改指针,判断next,prior指针是否为空,合法值的过滤(正确获得插入删除的位置),***

关于合法值的过滤,如果,使用length()函数其实也是一种思路,这样可以直接先把i不合法的情形过滤掉,直接返回错误,但是这样相当于先遍历一般链表,效率并不高啊,,所以不甚可取,因为在遍历过程中判断i值最好的情形是不用遍历一遍的

####!!!
所有这些细节的问题,在专业的写法中是如何解决实现的呢,,,,,
[http://www.cplusplus.com/reference/list/list/insert/](http://www.cplusplus.com/reference/list/list/insert/)

要看一下stl源码剖析了



########当插入位置是N+1的时候,
单链表就是找到第N个结点,没问题
双向链表是要找到第N+1个结点,并没有这个结点啊,,,其实就是头结点
所以
单链表的getposition(i)中i的合法值是0-N
双向循环链表的getposition(i)中i的合法值是0-N+1,这样在写
```DuLinkedList GetElemP_DuL(DuLinkedList L,int i)```
这个函数时,就要在循环结束后添加很多判断,,,


```
#include "head.h"
#include "DuLinkedList.h"

Status InitList_DuL(DuLinkedList& L)
{
	L=(DuLNode *)malloc(sizeof(DuLNode));
	L->next = L;
	L->prior = L;

	return OK;
}	

/*0<= i <= N*/
DuLinkedList GetElemP_DuL(DuLinkedList L,int i)
{
	//why this line ,,,,,
	//没有这一行,L为空&向i=1处插入时,没有返回头结点,返回了空指针
	if( i == 0) return L;

	/*
	*DuLinkedList p = L;
	*int j = 0;
	*/
	DuLinkedList p = L->next;
	int j = 1;

	while(p != L && j < i)
	{
		p = p->next;
		j++;
	}	
	/*i < 0:j>i
	* i > N:p == L
	*/
	if(p == L || j > i) return NULL;
	return p;
}


/*1<= i <= N
*1:first
*N:last
*head or NULL is wrong
*/
Status GetElem_DuL(DuLinkedList L,int i,ElemType &e)
{
	DuLinkedList p = GetElemP_DuL(L,i);
	if(p == L || !p) return ERROR;
	e = p->data;
	return OK;
}

/*1<= i <= N+1*/
/*0<= i-1 <= N*/
Status ListInsert_DuL(DuLinkedList L,int i,ElemType e)
{
	DuLinkedList p = GetElemP_DuL(L,i-1);
	if(p == NULL) return ERROR;
	DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
	s->data = e;

	
	p->next->prior = s;
	s->next = p->next;
	p->next = s;
	s->prior = p;

	return OK;
}

/*1<= i <= N
*1:first
*N:last
*head or NULL is wrong
*/
Status ListDelete_DuL(DuLinkedList L,int i,ElemType& e)
{
	DuLinkedList p = GetElemP_DuL(L,i);

	if(p == L || !p) return ERROR;

	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	return OK;
}
void ShowList_DuL(DuLinkedList &L)
{
	DuLinkedList p = L->next;
	int i = 1;
	while(p != L)
	{
		cout<<i<<":\t"<<p->data<<endl;
		p = p->next;
		i++;
	}
}
```