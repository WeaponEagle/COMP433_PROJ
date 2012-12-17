#include "data_structure/TermNode.h"

TermNode::TermNode(char* term, int df)
{
	this->posting = 0;
	this->term = term;
	this->df = df;
	this->nextNode = 0;
}

TermNode* TermNode::next()
{
	return this->nextNode;
}

void TermNode::add(TermNode* nextNodePtr)
{
	this->nextNode = nextNodePtr;
}
Posting* TermNode::getPosting()
{
	return this->posting;
}

char* TermNode::getTerm()
{
	return this->term;
}

int TermNode::getDocumentFrequency()
{
	return this->df;
}