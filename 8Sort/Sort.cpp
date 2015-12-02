#include "head.h"
#include "Reader"

void Sort::BInsertSort()
{
	cout<<"折半插入排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"折半插入排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}
void Sort::TPInsertSort()
{
	cout<<"两路插入排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"两路插入排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}
void Sort::ShellInsert()
{
	cout<<"希尔排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"希尔排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}
void Sort::BubbleSort()
{
	cout<<"冒泡排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"冒泡排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}
void Sort::QuickSort()
{
	cout<<"快速排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"快速排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}
void Sort::SelectSort()
{
	cout<<"选择排序演示------,原始数据:"<<endl;
	this->reader.ShowData();




	cout<<"选择排序演示------,结果数据:"<<endl;
	this->reader.ShowData();
	this->reader.Clear();
}