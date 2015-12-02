#include "head.h"
#include "Reader.h"
void BInsertSort()
{
	Reader reader;
	cout<<"binary insert sort demo------,origin data:"<<endl;
	reader.ShowData();

	for(int i =2;i < reader.length;i++)
	{
		if(reader.data[i] < reader.data[i-1])
		{
			reader.data[0] = reader.data[i];
			reader.data[i] = reader.data[i-1];

			int low = 1,high = i-2;
			int mid = (low+high)/2;
			int pos = 0;
			while(low <= high)
			{
				if(reader.data[0] < reader.data[mid])
				{
					high = mid-1;
					mid = (low+high)/2;
					pos = high;
				}
				else if(reader.data[mid] <= reader.data[0])
				{
					low = mid+1;
					mid = (low+high)/2;
					pos = low;
				}
			}


		}
	}

	cout<<"binary insert sort demo------,result data:"<<endl;
	reader.ShowData();
}