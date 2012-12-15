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
	TermNode(char* term, int df, Posting* posting);
	
	virtual Posting* getPosting();
	virtual char* getTerm();
	virtual int getDocumentFrequency();

private:
	Posting* posting;
	char* term;
	int df;
};