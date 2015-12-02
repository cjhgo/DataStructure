#include "head.h"
#include "Reader.h"

int Partition(int* data,int i,int j)
{
	int low = i;
	int high = j;
	int pivot = low;	
	int pivotkey = data[pivot];
	while(low < high)
	{
		int m = high;
		while(data[m] >= pivotkey)
		{
			m--;
			if(m <= pivot)break;
		}
		data[pivot] = data[m];
		pivot = m;
		high = m;

		m = low;
		while(data[m] < pivotkey)
		{
			m++;
			if(m >=pivot)break;
		}
		data[pivot] = data[m];
		pivot = m;
		low = m;
	}
	data[pivot] = pivotkey;
	return pivot;
}

void quicksort(int* data,int i ,int j)
{
	if(i <= j)	
	{
		int pos=Partition(data,i,j);
		quicksort(data,i,pos-1);
		quicksort(data,pos+1,j);
	}
}

void QuickSort()
{
	Reader reader;
	cout<<"quick sort demo------,origin data:"<<endl;
	reader.ShowData();
	quicksort(reader.data,1,8);
	cout<<"quick sort demo------,result data:"<<endl;
	reader.ShowData();
}


/**
void showdata(int *data)
{
	for(int i = 0;i < 8;i++)
	{
		cout<<data[i]<<TAB;
	}
	cout<<endl;
}
int Partition(int* data,int i,int j)
{
	int low = i;
	int high = j;
	int pivot = low;	
	int pivotkey = data[pivot];
	while(low < high)
	{
		int m = high;
		while(data[m] >= pivotkey)
		{
			m--;

			if(m <= pivot)break;
		}
		data[pivot] = data[m];
		// data[m] = pivotkey;
		pivot = m;
		high = m;

		showdata(data);
		cout<<low<<TAB<<high<<endl;

		m = low;
		while(data[m] < pivotkey&& m <= pivot)
		{
			m++;
			if(m >= pivot)break;
		}
		data[pivot] = data[m];
		// data[m] = pivotkey;	
		pivot = m;
		low = m;


		showdata(data);
		cout<<low<<TAB<<high<<endl;

		cout<<endl<<endl;
	}
	data[pivot] = pivotkey;
	showdata(data);
}
int data[8]={49,38,65,97,76,13,27,67};
	showdata(data);
	cout<<endl;
	Partition(data,0,7);
**/