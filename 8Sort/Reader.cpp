#include "head.h"
#include "Reader.h"

Reader::Reader(int number,char* name)
{
	this->length = number+1;
	this->filename = name;
	this->data = new int[this->length];	
	GetData();

}
Reader::Reader()
{
	this->length = 9;
	this->filename = "data.bin";
	this->data = new int[this->length];	
	GetData();

}
void Reader::GetData()
{
	
	ifstream infile;
	infile.open(this->filename,ios::in);

	int i = 1;
	while(!infile.eof())
	{
		infile>>this->data[i];
		i++;
	}
	infile.close();
}
void Reader::ShowData()
{
	for (int i = 1; i < this->length; ++i)
	{
		cout<<this->data[i]<<TAB;
	}
	cout<<endl;
}
void Reader::Clear()
{
	GetData();
}