viewport:width=device-width,initial-scale=1

目录

[TOC]

##KMP 算法

原理,要点

 + i指针不会退,i指针,主串指针不回退
 + 不会退,然后将第i个字符和模式串的第k个字符比较
 应满足什么什么关系?
 	- i往前数的k-1个字符
 	和
 	模式串的前k-1个字符匹配
 	只有这样,已经匹配了,不用比了,才可以和第k个字符比
 	(把握住这要求/原则)
 + 同时,根据,已匹配的信息知道(假设现在模式串匹配到第j个字符,然后匹配失败了)
 则
 	- i往前数的k-1个字符
 	和
 	模式串第j个字符往前数的k-1个字符是匹配的
 		+ i往前数的k-1个字符
 		和
 		模式串的前k-1个字符匹配
 	- 则
 	模式串的前k-1个字符匹配
 	和
 	模式串第j个字符往前数的k-1个字符是匹配的
 	- 这就是k的位置,next[]数组的涵义
 	next[j]=k
+ next数组怎么求,?分类讨论+递推
已知next[j],求next[j+1]
	- 图示
	![求next[j]](file://E:/Users/chen-pc/datastructure/4String/KMP_NEXT.png)
```c
/*
**
**
*/
next[j]=k,
next[k]=k'
if pattern[k]==pattern[j] 
	then next[j+1]= k+1
else if next[k'] == pattern[j]
	then next[j+1]=k'+1
else if
.
.
.
```	