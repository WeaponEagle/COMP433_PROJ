#include "data_structure/DataLoader.h"
#include <cmath>
/*
DataLoader::DataLoader(int hsize=0, TermNode * * htable=0, int MaxDocid=0)
{
	//this->hsize = hsize;
	//this->htable = htable;
	//this->MaxDocid = MaxDocid;
}
*/

void DataLoader::addTermNode(TermNode* node)
{
	//return 0;
}

TermNode* findTerm(char* searchTerm){
	return 0;
}
// Determine the hash value of the string s given the hash table size is h
// hash value is stored in hvalue
int DataLoader::hash(char* s) {
	char * t = s;
	int hvalue = 3;
	//if (s == NULL) return 0;

	while (*t != '\0') {
		hvalue = (31*hvalue + 57*((int) (unsigned char) *t));
		if (hvalue < 0) hvalue = -1 * hvalue;
		hvalue = hvalue % this->hsize;
		t++;
	}

	return hvalue;
}

