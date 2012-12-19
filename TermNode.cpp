#include "data_structure/TermNode.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

TermNode::TermNode(char* term, int df)
{
	//this->posting = 0;
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
vector<Posting*> TermNode::getPosting()
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

void TermNode::addPosting(int docid, int freq)
{
	Posting* posting = new Posting(docid,freq);
	this->posting.push_back(posting);
}
