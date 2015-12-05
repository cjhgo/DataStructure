viewport:width=device-width,initial-scale=1

目录

[TOC]


##数据结构进阶
[操作系统中的数据结构][7]
https://github.com/mirrors/linux-2.6/blob/master/include/linux/plist.h
https://github.com/mirrors/linux-2.6/blob/b3a3a9c441e2c8f6b6760de9331023a7906a4ac6/include/linux/prio_heap.h
https://github.com/mirrors/linux-2.6/blob/b3a3a9c441e2c8f6b6760de9331023a7906a4ac6/include/linux/hash.h
###堆与优先级队列
+ 用一般的队列实现的优先级队列
	- 出队操作$O(n):遍历队列,找出优先级最高的$
	- 入队操作$O(1):插入队尾即可$
+ 用按优先级排序的队列实现的优先级队列
	- 出队操作$O(1):从队头取出元素即可$
	- 入队操作$O(n):要遍历队列才能找到合适的插入位置$
+ 用堆实现的优先级队列
**<u>在出队和入队两方面,都具有良好的时间性能:O(logn)</u>**	
所以采用堆来实现优先级队列
	- 一个大根堆,根就是优先级最高的元素
	取走根元素后,调整堆,时间复杂度O(logn)
	- 入队操作,即向堆中插入一个元素
	也就是在堆的尾部添加一个元素,后调整
	时间复杂度O(logn)

**进一步学习链接**
[google 优先级队列 堆][6]
###排序
####哈希
#####hash bucket
把哈希表看成由相同大小的桶组成
即,把一维数组按定长分组
$数组长m,桶的size为n,则有m/n=d个桶\\\
同时设置有一个公共缓冲区\\\
计算hash地址时,有两种思路\\\$

+ 一种思路是$H(key)=key % d,\\\
各个记录一次放到桶里边\\\
桶满的时候,放到公共缓冲区\\\$
	- 查找的时候
		+ 先根据$H(key)=key % d$算出桶号
		遍历桶
			- 找到空,说明查找失败
			- 没找到空,那么自然桶是满的,
			同时又遍历一遍没找到
			那么就去
		+ 遍历公共缓冲区
+ 另一种思路是:一开始的时候,桶是透明的
即按$H(key)=key % m(表长)算哈希地址\\\
这样可选的位置是整个表,而不是仅限于某个桶\\\$
	- $当产生冲突时,才启用桶,\\\
	即:用H(key)=key % m(表长)算出的地址处已被占据时\\\
	就从地址所在的桶内找空位$		

**参考链接**	
[google hash bucket][4]
[Bucket Hashing][0]
[哈希表的C实现（三）---传说中的暴雪版][1]
[代码实现,][3]



[0]:http://algoviz.org/OpenDSA/Books/OpenDSA/html/BucketHash.html#HashingBucket2PRO
[1]:http://www.cnblogs.com/xiekeli/archive/2012/01/17/2324433.html
[3]:http://pokristensson.com/strmap.html
[4]:https://www.google.com.hk/#newwindow=1&q=hash++bucket
[5]:http://www.memorymanagement.org/mmref/index.html#mmref-intro
[6]:https://www.google.com.hk/#newwindow=1&q=优先级队列+堆
[7]:http://www.zhihu.com/question/27943222/answer/38739231