#include "head.h"
#include "Reader.h"
void InsertSort()
{
	Reader reader;
	cout<<"insert sort demo------,origin data:"<<endl;
	reader.ShowData();

	for(int i = 2;i < reader.length;i++)
	{
		if(reader.data[i] < reader.data[i-1])
		{
			reader.data[0] = reader.data[i];
			
			reader.data[i] = reader.data[i-1];

			int j = i-2;
			for(;reader.data[j] > reader.data[0];j--)
			{
				reader.data[j+1] = reader.data[j];
			}

			reader.data[j+1] = reader.data[0];
		}

	// debug::reader.ShowData();

	}

	cout<<"insert sort demo------,result data:"<<endl;
	reader.ShowData();
}