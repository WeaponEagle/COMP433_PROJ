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
	TermNode* findTerm(char* searchTerm);
	virtual void addTermNode(TermNode* node);

private:
	int hsize;
	TermNode** htable;
	int MaxDocid;
	int hash(char* searchTerm);
	
};