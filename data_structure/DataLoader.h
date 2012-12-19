///////////////////////////////////////////////////////////////////////////////////////
// 
// Term node Data Structure - link-listed data structure
// Constructed by term
//
////////////////////////////////////////////////////////////////////////////////////////

#include "data_structure/TermNode.h"
#pragma once
#include <string>
#include <vector>
#include <map>
using namespace std;
class DataLoader
{
public:
	void loadData(char *file_name);
	unsigned int hash_gen(char* term); //takes the age and converts it into an index into the array of linked lists
	void add(char *term, int df);
	void display(); //prints the hash table
	//void DataLoaderable_delete(char *name, int age);
	//~DataLoader(void);
private:
	int tsize;
	//TermNode ** myArray;
	map<int, vector<TermNode*>> myArray;
};