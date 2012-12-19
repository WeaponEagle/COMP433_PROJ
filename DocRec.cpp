#include "data_structure/DocRec.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

DocRec::DocRec(int docid, int doclen, string status, string docName, string filePath)
{
	this->docid = docid;
	this->doclen = doclen;
	this->status = strdup(status);
	this->docName = strdup(docName);
	this->filePath = strdup(filePath);
}
