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
	unsigned int hash_gen(int age_value); //takes the age and converts it into an index into the array of linked lists
	void DataLoaderable_add(char *new_name, int new_age);
	void DataLoaderable_display(); //prints the hash table
	void DataLoaderable_delete(char *name, int age);
	~DataLoader(void);
private:
	class Node{
	public:
		Node(char * newName, int age)
			:age(age), next(0)
		{
			strncpy(name, newName, 1024);
			this -> next = 0;
		}
		Node()
		{
		}
		char name [1024];
		int age;
		Node * next;
	};
	int tsize;
	Node ** myArray;
};