#include "data_structure/Posting.h"

Posting::Posting(int docid, int freq,  Posting* nextNode)
{
	this->docid = docid;
	this->freq = freq;
	this->nextNode = nextNode;
}

int Posting::getDocumentId()
{
	return this->docid;
}

int Posting::getTermFrequency()
{
	return this->freq;
}

Posting* Posting::next()
{
	return this->nextNode;
}