#include "data_structure/Posting.h"

Posting::Posting(int docid, int freq)
{
	this->docid = docid;
	this->freq = freq;
}

int Posting::getDocumentId()
{
	return this->docid;
}

int Posting::getTermFrequency()
{
	return this->freq;
}