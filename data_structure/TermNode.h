///////////////////////////////////////////////////////////////////////////////////////
// 
// Term node Data Structure - link-listed data structure
// Constructed by term
//
////////////////////////////////////////////////////////////////////////////////////////

#include "data_structure/Posting.h"
#include <vector>
#include <map>
using namespace std;

class TermNode
{
public:
	TermNode(char* term, int df);
	virtual vector<Posting*> getPosting();
	virtual void addPosting(int docid, int freq);
	virtual void add(TermNode* nextNodePtr);
	virtual TermNode* next();
	virtual char* getTerm();
	virtual int getDocumentFrequency();

private:
	vector<Posting*> posting;
	TermNode* nextNode;
	char* term;
	int df;
};