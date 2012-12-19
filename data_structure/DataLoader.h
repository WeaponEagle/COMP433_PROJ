#pragma once
#include <string>
#include "data_structure/DocRec.h"
#include "data_structure/TermNode.h"

class DataLoader
{
public:
	void loadInvFile(char *file_name);
	void loadDocRec(char *file_name);
	void loadDocLen(char *file_name);
	void display();
	TermNode* findTerm(const char* term);
	int getTotalDocuments();
	double getDocumentLengthById(int docid);
	
private:
	int hashSize;
	int totalDoc;
	void add(TermNode* node);
	unsigned int hashGen(const char* term); //takes the age and converts it into an index into the array of linked lists
	void invFileSingleLineProcess(char* lineBuffer);
	map<int, vector<TermNode*>> invFile;
	vector<DocRec*> documentRecords;
};