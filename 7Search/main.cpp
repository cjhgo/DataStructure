#include "head.h"
#include "search.h"
int main(int argc, char const *argv[])
{
	int seq[11] = {0,1,99,2,33,7,8,6,22,32,72};
	int bin[11] = {0,3,7,9,11,22,25,27,88,99};
	int key = 22;
	
	int pos = search_seq(seq,10,key);
	cout<<pos<<TAB<<seq[pos]<<endl;
	pos = search_bin(bin,10,key);
	cout<<pos<<TAB<<bin[pos]<<endl;
	return 0;
}