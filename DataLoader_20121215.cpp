
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structure/DataLoader.h"
#include <cmath>

DataLoader::DataLoader()
{
	this->hsize = 0;
	this->htable = NULL;
	this->MaxDocid = 0;
	this->MakeHashTable();
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

// Create a hash table of size h
// Initialize this hash table of pointers to NULL
void DataLoader::MakeHashTable() {
	if (this->hsize > 0) {
		this->htable = (TermNode **) calloc(this->hsize, sizeof(TermNode *));
		for(int i=0; i < this->hsize; i++) {
			this->htable[i] = NULL;
		}
	}
}


// Insert an hnode structure into the hash table
// Initialize the structure with the string s
void DataLoader::addTermNode(TermNode* TermNode) {
	this->htable[0]=TermNode;
}