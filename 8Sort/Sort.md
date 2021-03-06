viewport:width=device-width,initial-scale=1

目录

[TOC]

##sort排序
###概述
**排序确切的定义**
$含有n个记录的序列为\\{R_1,R_2,\cdots,R_n\\}\\\
其相应的关键字序列为\\{K_1,K_2,\cdots,K_n\\},\\\
需确定1,2,\cdots,n的一种排列为p_1,p_2,\cdots,p_n,使其相应的关键字满足非递减或非递增关系\\\
\quad\quad\quad K_{p_1}\leqslant K_{p_2}\leqslant \cdots K_{p_n}\\\
使序列称为一个按关键字有序的序列\\\
\quad\quad\quad \\{R_{p_1}, R_{p_2}, \cdots R_{p_n}\\}
如果K_i是主关键字,因其不允许重复,得到的排序结果是唯一的\\\$
如果K_i是次关键字,有可能存在两个或两个以上关键字相等,排序序列不唯一,
相应的排序方法就有<u>稳定与不稳定之分</u>

**内排序与外排序**

+ 内排序:记录一次读入内存
+ 外排序:记录过多无法一次读入内存,,??在排序过程中尚需对外存进行访问

**内排序方法分类**

+ 依据**<u>不同原则</u>**分类
五类排序算法
	- 插入排序
		+ 直接插入排序
		+ 折半插入排序
		+ 希尔排序
	- 交换排序
		+ 冒泡排序
		+ 快排
	- 选择排序
		+ 直接选择排序
		+ 树形选择排序
		+ 堆排序
	- 归并排序
	- 基数排序
+ 依据排序所需工作量分类
	- 简单排序方法,$O(n^2)$
	- 先进排序方法,$O(nlogn)$
	- 基数排序,$O(d\cdot n)$

**排序过程中的基本操作**

+ *比较*关键字大小
+ 将记录从一个位置*移动*至另一个位置
	- 通过改变记录存储方式避免
		+ 顺序存储
		+ 静态链表
		+ 顺序存储+地址向量
+ 讨论算法复杂度时,也就会分别讨论比较次数和移动次数		
###插入排序
####直接插入排序
思想
>将一个记录插入到已排好序的有序表中;
将序列中的第1个记录看出是一个有序的子序列,从第2个记录起逐个进行插入

#####**效率分析**

+ 空间复杂度:一个记录的辅助空间
+ 时间复杂度:
	- 最好情况:记录已经`正序`$O(n)$
		+ 比较次数:$\sum\limits_{i=2}^{n}1=n-1$
			- $a[i]只需要和a[i-1]比较一次进行了$
		+ 移动次数:不需要移动$0$
	- 最坏情况:记录`逆序`
		+ 比较次数:$\sum\limits_{i=2}^{n}i=\frac{(n-2)(n-1)}{2}$
			- $a[i]要一直比较到a[0],从a[0]到a[i-1]比较了i次$
		+ 移动次数:$\sum\limits_{i=2}^{n}i+1=\frac{(n+4)(n-1)}{2}$
			- $a[i]赋给a[0];a[1]-a[i-1]后移赋值;a[i]的值赋给a[1],\\\赋值操作共计i+1次$
	- <u>若待排序记录是随机的,即记录可能出现的各种排列概率相同,可以取最大值和最小值的平均值</u>$n^2/4$
	- 直接插入排序时间复杂度$O(n^2)$
####其他插入排序
#####折半插入排序
>用折半查找得到记录插入的位置,减少比较的次数,记录移动的次数不变

时间复杂度$O(n^2)$
#####2-路插入排序
需要n个记录的辅助空间作为一个循环向量
用first和final指针分别指向有序序列的收尾位置,(而不是按数组下标有序)
<u>来减少记录移动的次数</u>

当原始记录第一个键值是最值时,循环向量起不了作用,算法也无法减少记录移动次数
#####表插入排序
<u>通过使用静态链表来减少记录移动的次数</u>
??重排记录的做法,,?
####希尔排序,缩小增量排序
>:将整个待排记录(按增量)分割为若干个子序列分别进行直接插入排序
带整个序列中的记录'基本有序'时,对对全体记录进行一次直接插入排序
利用了基本有序时插入排序时间复杂度提高到O(n)的特性

```c
ShellSort()
{
	// 增量序列,例如:9,5,3,...递减,也就是缩小增量序列
	dlta[0...t-1]
	for(k = 0; k < t; ++k)
	{
		/**
		**按dlta[k]的取值,对待排序序列按dlta[k]的间隔分成多个子序列
		**对各个子序列进行插入排序
		**子序列插入排序时,前后记录位置每次变化dlta[k],而不是1
		**/
		ShellInsert(L,dlta[k])
	}
}
```
###交换排序
借助`交换`排序
####冒泡排序
>比较相邻记录(的关键字),逆序时交换相邻记录,
每一趟排序使得关键字最大的记录被交换到 本趟范围内的最后一个位置
结束条件:在一趟排序过程中没有进行过交换记录的操作

#####**效率分析**

+ 时间复杂度分析
	- 最好情况:记录已经`正序`,只需$1$趟排序
	在这一趟排序中,没有发生过记录交换,排序宣告结束
	一趟排序中
		+ 比较$n-1次关键字,$
		+ $不移动记录$
	- 最坏情况:记录是`逆序`的,需要$n-1趟排序$
	在每趟排序中
		+ 比较$i-1次$,共计比较$\sum\limits_{i=n}^{2}(i-1)=n(n-1)/2次$
		+ 移动/交换$i-1次$,共计交换$\sum\limits_{i=n}^{2}(i-1)=n(n-1)/2次$
		
####快速排序
```c
void QuickSort(L)
{
	/**QSort递归调用
	**最终有序
	**/
	QSort(L,1(low),L.length(high))
				
		if(low < high)
		{			
					/**Partition:一趟快速排序
					**以L[low]为轴将L一份为二
					**得到一个pivot(轴)的位置(location)
					**使得轴左边的记录 < 轴 < 轴右边的记录
					**/
			PivotLoc=Partition(L,low,high)
			QSort(L,low,PivotLoc-1)
			QSort(L,PivotLoc+1,high)	
		}
}
```
#####**效率分析**
<u>就平均时间而言,快速排序目前被认为是最好的一种内部排序方法</u>

+ 时间复杂度分析
	- $T(n)为对n个记录进行快速排序所需时间,\\\
	T_{pass}(n)为对n个记录进行一趟快速排序所需时间\\\
	T(n)=T_{pass}(n)+T(k-1)+T(n-k),(PivotLoc=k)$
	- $T_{pass}(n)=cn,因为Partition是从表的两端交替地向中间扫描\\\
	只需遍历表一遍就可完成操作,时间复杂度O(n)=cn,c为某个常数$
	- $快速排序所需平均时间\\\
	记录随机排序,则一趟排序后,k取[1,n]之间任何一值概率相同\\\
	T_{avg}(n)=cn+ \frac{1}{n}\sum\limits_{k=1}^{n}[T_{avg}(k-1)+T_{avg}(n-k)]\\\
	=\cdots\\\
	< \cdots\\\
	=O(nlogn)$
	- 若初始记录序列按关键字有序或基本有序(比如逆序)的时候,
	枢轴的值往往是最值,每次partition后序列长度减一/(枢轴两边的序列长度不均匀,,)
	快速排序就蜕化为了冒泡排序
		+ 为解决这个问题<u>用三者取中</u>的法则来避免枢轴取成最值
		即取$L[s],L[\frac{s+t}{2}],L[t]三者关键字的中值为枢轴$
		来改善快速排序在最坏情况下的性能
	- 修改`一次划分`,
	在partition的同时进行冒泡操作,
	进一步改善性能
+ 空间复杂度
	- 栈空间深度
###选择排序:找无序序列中的最小值/找第i小的值
基本思想
>每一趟在a[i],a[i+1]...a[n]这n-i+1个记录中选择关键字最小的记录
作为这个子序列的第一个记录也就是有序序列的第i个记录
####简单选择排序
基本思想
$第i趟简单选择排序在a[i]...a[n]这n-i+1个记录中作n-i次比较,\\\
(a[i]和\\{a[i+1],\cdots,a[n]\\}比,共计比n-i次)\\\
选择出关键字最小的记录,也就是整个序列中第i小的记录,和a[i]交换\\\
总计需要n-1趟\\\
第1趟让a[1]和\\{a[2],\cdots,a[n]\\}比较\\\
\vdots\\\
第n-1趟,比较a[n-1]和a[n]$

```c
void SelectSort(L)
{
	for(i = 1;i< L.length;++i)
	{
		j = SelectMinKey(L,i);
		if(i != j) L[i]<->L[j];
	}
}
```
#####**效率分析**
+ 时间复杂度
	- 最好情况:序列已经`正序`
		+ 移动次数:每一趟都不需要交换记录,$0$
		+ 比较次数:每一趟比较$n-i次\\\
		共计比较\sum\limits_{i=1}^{n-1}n-i=n(n-1)/2$
	- 最坏情况:序列`逆序`
		+ 移动次数:每一趟都要交换,交换两个记录需要三次赋值,共计交换/移动$3(n-1)$
		+ 比较次数:和最好情况下相同

>在n个关键字中选出最小值,至少要进行n次比较
然而继续在剩余的n-1个关键字中选择次小值并不一定要n-2次比较
利用关系的传递性,前n-1次比较所得的信息,可以减少以后各趟选择排序中所用的比较次数		
####树形选择排序
含有n个叶子结点的**完全二叉树**
形态是确定的,当n为奇数的时候

+ 构造这个完全二叉树的过程就是选出最小值的过程
最小值出现在根结点位置上
+ 中间的比较信息保存在了这个树结构中
+ 把最小值换成$\infty,然后从此叶节点再比较到根节点,就得到了次最小值$
+ 依次重复类似操作,得到次次最小值,次次次最小值,,,

缺点:需要较多的辅助存储空间
排序n个数,就要构造一棵含有n个叶子结点的完全二叉树

####堆排序
堆排序同样利用了树形选择排序用到的思想,但是改善了存储空间的要求
#####堆的定义(元素大小满足特殊条件的序列)
$n个元素的序列\\{k_1,k_2,\cdots,k_n\\}当且仅当满足如下关系时,称之为堆\\\
\begin{equation}
	小根堆
	\begin{cases}
	k_i \leqslant k_{2i}\\\
	k_i \leqslant k_{2i+1}
	\end{cases}
\end{equation}
堆顶元素取最小值
$
$
\begin{equation}
	大根堆
	\begin{cases}
	k_i \geqslant k_{2i}\\\
	k_i \geqslant k_{2i+1}	
	\end{cases}
\end{equation}
堆顶元素取最大值
$
**<u>堆是一个特殊的序列,若将和此序列对应的一维数组看成一个完全二叉树
则这棵完全二次树有这样的特点:所有非终端结点的值均不大于其左右孩子结点的值
也可以说,在双亲,左孩子,右孩子三者中的双亲是最值,(最大值/最小值)
(左右孩子结点的值的大小关系则不确定)
</u>**

#####堆排序
要解决两个问题

+ 如何把一个无序序列建成一个堆:`反复筛选`
	- 将无序序列看成是一个完全二叉树
	从最后一个非终端结点开始向上筛选到根结点
	就得到由一个无序序列得到一个堆
		+ 最后一个非终端结点位置$n/2向下取整$
		+ 这样做的效率比一开始看做是空堆(即像链表那样,通过插入操作建链表),
		元素一个个插入的效率要高
			- 一个个插入每插入一次都要调整
			- 这一点和链表不一样
+ 在已经有一个堆的前提下,
输出堆顶元素后,如何调整剩余元素称为一个新堆
	- 以堆中最后一个元素代替堆顶元素(这样影响最小)
		+ 最后一个元素是指,从根开始,一层层编号
	- 代替之后,看根结点数值是否是根,左右孩子三者中最下的
	若不是,`{根结点}<->{最值所在结点}`
		- 交换之后,看是否又破坏了子树根结点的`堆`
		$\vdots$
	- 这个自堆顶到叶子的调整过程称为`筛选`

```c
/**
**输出堆顶的最大值之后,使得剩余元素序列重新建成一个堆
**输出次最大值,如此反复执行
**得到一个有序序列
**/
void HeapSort(H)
{	
	//通过反复筛选将无序序列建成堆
	for(i = H.length/2;i > 0 ;--i)
	{	
		/**
		**筛选算法
		**/
		HeapAdjust(H,i,H.length);
	}

	for(i = H.length;i > 1;--i)
	{	
		//输出堆顶最值
		H[1]<->H[i];
		
		//调整剩余序列为新堆
		HeapAdjust(H,1,i-1);
	}
}
```	
#####效率分析
+ 时间复杂度
	- 将无序序列调整为堆/建初始堆:比较次数不超过$4n$
		+ 对记录数较少的文件不提倡使用堆排序
		因为初始建堆就用去不少时间$4n$
	- $选出第i小的值,调整堆操作\\\
	对深度为k的堆,筛选/调整堆的比较次数至多为2(k-1)次:每层和左右孩子比较一次\\\
	总共的比较次数不超过2n(\lfloor log_2n\rfloor)$
	- 最坏情况下:$O(nlogn)$
###归并排序
>将两个或两个以上的有序表合成为一个新的有序表


+ 两个有序序列归并的时间复杂度:$O(m+n),即两个序列扫描一遍即可完成$
+ 将n个无序记录看出n个有序的子序列
+ 核心操作:将一维数组中前后相邻的两个有序序列归并为一个有序序列
+ 最后一趟归并得到了一个有序序列
####2路归并排序


```c
//递归实现
void MergeSort(L)
{
	MSort()
	{
		MSort()
		MSort()
		Merge()
	}
}
```

+ 递归怎么来的,问题缩小规模,用同样的思想解决
	- 把两个有序序列归并
		- 从一个无序序列得到两个有序序列
			+ 无序序列分成两个子序列
			对这两个子序列分别进行归并排序
			$\vdots$
			+ 子序列长度一直减少,到了长度为2的子序列
			对长度为2的子序列归并排序
				- 得到两个长度为1的子序列
####效率分析
+ 时间复杂度:
	- 整个归并排序共需进行$log_2n向上取整趟,每趟归并O(n)\\\
	O(nlogn)$
+ 与快速排序和堆排序相比,归并排序的最大特点是**归并排序是一种稳定的排序方法**
###基数排序
>不需要进行关键字之间的比较
一种借助多关键字排序的思想对单逻辑关键字排序的方法


####多关键字排序
$含有n个记录的序列为\\{R_1,R_2,\cdots,R_n\\}\\\
如果么个记录R_i含有d个关键字(K_i^0,K_i^1,\cdots,K_i^{d-1})\\\
序列对关键字(K^0,k^1,\cdots,K^{d-1})有序是指\\\
对于序列中任意两个记录R_i和R_j都满足下列有序关系\\\
\quad\quad\quad\quad (K_i^0,K_i^1,\cdots,K_i^{d-1}) < (K_j^0,K_j^1,\cdots,K_j^{d-1})\\\
其中K^0称为最主位关键字,K^{d-1}称为最次位关键字\\\$

关键字的优先级是指,比较两个记录是先看这个关键字,而不管其他关键字大小关系如何
若相同,则依次看比较下一级的关键字

多关键字排序有两种方法


#####MSD最高位优先,容易理解
+ 先按最高级关键字排序,将序列分为若干个子序列
+ 对每个子序列各自按次一级关键字排序
$\vdots$
+ 最后将所有子序列依次连接在一起成为一个有序序列
+ 必须要采用稳定的排序方法,否则就破坏了较高优先级已拍好的序列
#####LSD最低位优先,不易理解
+ **<u>不必逐层分割成若干子序列,
每次对一级关键字排序都是从整个序列中按找关键字进行排序</u>**
+ 感性理解LSD:序列已经按低级关键字分组,....
所以,按本级关键字排序时,,

捋一下关系,,,

+ 多关键字排序无论MSD,还是LSD都可以利用关键字的比较来实现排序
+ 另一方面,在按LSD进行排序时也可有不用关键字比较的排序方法`分派,收集`
基数排序正是借鉴了这种方法:
####链式基数排序_没有进行关键字的比较
>怎样用多关键字排序的思想对单关键字序列排序?
把单关键字看出由若干个关键字复合而成的
这是要义所在

+ 关键字是数字,看成个十百千
+ 关键字是字符串,看成一个个字母

#####分配,收集
+ 分配/收集操作没有关键字比较过程,根据关键字直接得到对应队列的位置
所以说,基数排序时和前边讲的思路不同的排序方法
+ 分配:根据每一级关键字可能取值,设置队列个数
然后根据将序列中的值的对应关键字,按在序列中的出现顺序,加入到相应队列中
+ 收集:去除空队列,将队列串成一个链表
+ **<u>第i次分配之后通过收集得到的序列是按最低级到第i级关键字有序的</u>**
#####效率分析
+ 时间复杂度:
	- 需要d趟分配,收集
	- 分配需要遍历静态链表一遍,n,收集遍历所有队列一遍rd
	- $O(d(n+rd))$
+ 空间复杂度:
	- 需要存放队列指针...
###各种内部排序方法的比较讨论
五类8种内部排序算法
|算法|最好情况|平均情况|最坏情况|空间复杂度|稳定否|
|-|-|-|-|-|-|
|直接插入排序|$O(n)$|$O(n^2)$|$O(n^2)$|$O(1)$|是|
|冒泡排序|$O(n)$|$O(n^2)$|$O(n^2)$|$O(1)$|是|
|简单选择排序|$O(n^2)$|$O(n^2)$|$O(n^2)$|$O(1)$|否|
|希尔排序||||$O(1)$|否|
|快排|$O(nlogn)$|$O(nlogn)$|$O(n^2)$|$O(logn)$|否|
|堆排序|$O(nlogn)$|$O(nlogn)$|$O(nlogn)$|$O(1)$|否|
|二路归并排序|$O(nlogn)$|$O(nlogn)$|$O(nlogn)$|$O(n)$|是|
|基数排序|$O(d(n+r)$|$O(d(n+r)$|$O(d(n+r)$|$O(r)$|是|

####时间复杂度的讨论/初始状态对比较次数的影响
+ 初始排序/原始状态不影响 比较次数/时间复杂度的排序算法
	- 简单选择排序:
		+ $简单选择排序每次从n个数中选出最小值\\\
		无论如何需要比较O(n)次比较(没有利用之前的比较信息)$
		+ 即使序列初始已经`正序`,第一个就是最小值
		但`正序`在算法中无法体现/算法并没有利用序列的顺序
		$仍要比较n次才能确定出一个最小值$
		+ 序列初始排序为`正序`可以减少交换次数,比较次数不变
		算法时间复杂度仍是O(n^2)
	- 归并排序:
		+ 归并排序无论如何要扫描一遍各个子序列来完成归并
		不受序列的初始排序影响
	- 折半插入算法
+ 初始状态影响时间复杂度的算法
	- 直接插入排序,
	- 冒泡排序在最好情况下时间复杂度$O(n)$
	- 快排在最坏情况下蜕化为冒泡排序	
	- 堆排序,,,
####空间复杂度的讨论
+ 归并排序需要$O(n)的辅助空间用于元素复制$
####稳定性的讨论
**关于稳定性与不稳定性的理解**
不稳定的算法,无论如何实现/程序怎么写,总能找到不稳定的例子,
即找到一组序列,程序怎么写,都是不稳定的
稳定的算法,也许有的实现是不稳定的,但总能找到一种实现,是稳定的
#####稳定的排序算法
+ 一般来说,排序过程中的`比较`是在`相邻的两个记录关键字`间进行的排序方法是稳定的
	- `直接插入排序,冒泡排序`就是如此
+ 在基于比较的,时间性能较好的排序方法中,只有`归并排序`时稳定的
+ 基数排序是稳定的,它要求稳定
+ 折半插入排序时稳定的
#####不稳定的排序算法
+ 希尔排序不稳定
	- 记录的比较是跳跃式进行的
+ 快排不稳定
	- 记录的比是跳跃式的
+ 堆排序不稳定
	- 记录的比较是跳跃式进行的

所以,简单选择排序到底是不是稳定的,?
```
在一趟选择，如果当前元素比一个元素小，而该小的元素又出现在一个和当前元素相等的元素后面，
那么交换后稳定性就被破坏了。
比较拗口，举个例子，序列5 8 5 2 9， 我们知道第一遍选择第1个元素5会和2交换，
那么原序列中2个5的相对前后顺序就被破坏了，所以选择排序不是一个稳定的排序算法。
http://blog.csdn.net/hkx1n/article/details/3922249
```
**<u>用判定树可以证明,基于`比较`的排序方法,
当关键字随机分布时,至少需要$O(nlogn)的时间$</u>**
?最坏情况下能达到的最好的时间复杂度为$O(nlogn)$
?到底是平均,还是最坏,,,
####各个排序排序算法的比较,区别
+ 直接插入排序时在有序序列中找*插入*位置,
<u>比较操作在有序序列中进行</u>;
+ 简单选择排序时从无序序列中*选择*最小值作为有序序列的元素,
<u>比较操作(找最小值)在无序序列中进行</u>
+ 冒泡排序每次选出最大值顶到后面
<u>比较操作时相邻比较</u>




TODO
+ 五类排序算法,专题,
!!归并排序的理解http://www.cnblogs.com/kubixuesheng/p/4355865.html
http://www.cnblogs.com/kubixuesheng/
+ google 数据页面尚未分配 数组按先行后列存放
http://m.shangxueba.com/ask/2295200.html
http://www.cskaoyan.com/viewthread.php?action=printable&tid=80105
+ 高斯消元法,矩阵的本质的理解
http://blog.csdn.net/u010182633/article/details/45225179
+ baidu/google 堆排序 初始状态 
http://www.cskaoyan.com/thread-67550-1-1.html
http://www.zybang.com/question/d5ac76903b092ff214bb830ec6fe431d.html
http://www.cnblogs.com/cj723/archive/2011/04/22/2024269.html
+ 简单选择排序 稳定
+ 各种排序算法的稳定性的说明http://blog.csdn.net/hkx1n/article/details/3922249
+ 什么是分区文件 google 分区文件
子树也是堆，递归地，任何结点小于其子孙
+ google 外排序 多路归并
+ https://www.google.com.hk/#newwindow=1&q=%E6%8A%98%E5%8D%8A%E6%9F%A5%E6%89%BE+%E5%A4%B1%E8%B4%A5+%E6%9F%A5%E6%89%BE%E9%95%BF%E5%BA%A6

