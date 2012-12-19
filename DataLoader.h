///////////////////////////////////////////////////////////////////////////////////////
// 
// Term node Data Structure - link-listed data structure
// Constructed by term
//
////////////////////////////////////////////////////////////////////////////////////////

#include "data_structure/TermNode.h"
#pragma once
#include <string>
class DataLoader
{
public:
	void loadData(char *file_name);
	unsigned int hashGen(char* term); //takes the age and converts it into an index into the array of linked lists
	void add(TermNode* node);
	void display(); //prints the hash table
	TermNode* findTerm(char* term);
	//void DataLoaderable_delete(char *name, int age);
	//~DataLoader(void);
private:
	int tsize;
	void invFileSingleLineProcess(char* lineBuffer);
	map<int, vector<TermNode*>> myArray;
};