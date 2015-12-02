//length 是数据长度,数组长度=length+1(监视哨)
int search_seq(int data[],int length,int key)
{
	data[0] = key;
	int j = length;
	while(data[j] != key)
	{
		j--;
	}

	return j;
}
int search_bin(int data[],int length,int key)
{
	int low = 1;
	int high = length;
	int mid = (low + high) / 2;
	while(low <= high)
	{
		if(data[mid] == key) return mid;
		else if(key < data[mid])  high = mid -1;
		else if(data[mid] < key)  low  = mid +1;
	}

	return 0;
}		