#include "data_structure/TermNode.h"
#include "data_structure/DocRec.h"
#pragma once
#include <string>
class DataLoader
{
public:
	void loadData(char *file_name);
	void display(); //prints the hash table
	TermNode* findTerm(const char* term);
	int getTotalDocuments();
	double getDocumentLengthById(int docid);
	
private:
	int tsize;
	void add(TermNode* node);
	unsigned int hashGen(const char* term); //takes the age and converts it into an index into the array of linked lists
	void invFileSingleLineProcess(char* lineBuffer);
	map<int, vector<TermNode*>> invFile;
	vector<DocRec*> documentRecords;

};