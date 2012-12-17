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
	DataLoader(void);
	DataLoader(int tsize);
	unsigned int hash_gen(char* term); //takes the age and converts it into an index into the array of linked lists
	void DataLoaderable_add(char *new_name, int new_age);
	void DataLoaderable_display(); //prints the hash table
	void DataLoaderable_delete(char *name, int age);
	~DataLoader(void);
private:
	int tsize;
	TermNode ** myArray;
};