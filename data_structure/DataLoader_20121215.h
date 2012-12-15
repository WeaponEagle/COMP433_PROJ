///////////////////////////////////////////////////////////////////////////////////////
// 
// Term node Data Structure - link-listed data structure
// Constructed by term
//
////////////////////////////////////////////////////////////////////////////////////////

#include "data_structure/TermNode.h"

class DataLoader
{
public:
	//DataLoader(int hsize, TermNode * * htable, int MaxDocid);
	DataLoader();
	TermNode* findTerm(char* searchTerm);
	virtual void addTermNode(TermNode* node);
	virtual void MakeHashTable();
private:
	int hsize;
	TermNode** htable;
	int MaxDocid;
	int hash(char* searchTerm);
	
};