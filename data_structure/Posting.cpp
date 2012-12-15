#include "Posting.h"

Posting::Posting(int id, int freq, char* term, Posting* next)
{
	this->id = id;
	this->freq = freq;
	this->term = term;
	this->next = next;
}

int Posting::getDocumentId()
{
	return this->id;
}

int Posting::getTermFrequency()
{
	return this->freq;
}

char* Posting::getTerm()
{
	return this->term;
}

Posting* Posting::getNext()
{
	return this->next;
}