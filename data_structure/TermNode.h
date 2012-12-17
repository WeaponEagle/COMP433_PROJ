///////////////////////////////////////////////////////////////////////////////////////
// 
// Term node Data Structure - link-listed data structure
// Constructed by term
//
////////////////////////////////////////////////////////////////////////////////////////

#include "data_structure/Posting.h"

class TermNode
{
public:
	TermNode(char* term, int df);
	virtual Posting* getPosting();
	virtual void add(TermNode* nextNodePtr);
	virtual TermNode* next();
	virtual char* getTerm();
	virtual int getDocumentFrequency();

private:
	Posting* posting;
	TermNode* nextNode;
	char* term;
	int df;
};