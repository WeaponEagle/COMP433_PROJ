#include "data_structure/TermNode.h"

TermNode::TermNode(char* term, int df, Posting* posting)
{
	this->posting = posting;
	this->term = term;
	this->df = df;
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