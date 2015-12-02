#include "head.h"
#include "Reader.h"

int SelectMin(int * data,int i,int j)
{
	int min = data[i];
	int pos = i;
	for(int m = i+1;m <= j;m++)
	{
		if(data[m] < min)
		{
			min = data[m];
			pos = m;
		}
	}
	return pos;
}
void SelectSort()
{
	Reader reader;
	cout<<"select sort demo------,origin data:"<<endl;
	reader.ShowData();
	// cout<<endl;

	for(int i = 1;i < 8;i++)
	{
		int min_i_pos=SelectMin(reader.data,i,8);
		// cout<<min_i_pos<<endl;
		int temp = reader.data[i];
		reader.data[i] = reader.data[min_i_pos];
		reader.data[min_i_pos] = temp;
		// reader.ShowData();
		// cout<<endl<<endl;
	}

	cout<<"select sort demo------,result data:"<<endl;
	reader.ShowData();
}