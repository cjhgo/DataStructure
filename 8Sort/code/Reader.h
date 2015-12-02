#ifndef READER_H
#define READER_H

class Reader
{
public:
	Reader();
	Reader(int number,char* name);
	~Reader(){};
	int length;
	void ShowData();
	void Clear();
	int* data;
private:
	char* filename;	
	void GetData();
	/* data */
};

#endif