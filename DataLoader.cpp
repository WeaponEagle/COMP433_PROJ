
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structure/DataLoader.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

DataLoader::DataLoader(void)
	:tsize(10)
{
	myArray = new Node * [10];
	for (int i = 0; i < 10; i++)
		myArray [i] = 0;
	cout<<"Default Constructor Called \n";
}

DataLoader::DataLoader(int tsize)
	:tsize(tsize)
{
	myArray = new Node * [tsize];
	for (int i = 0; i < tsize; i++)
		myArray[i] = 0; 
	cout<<"Constructor Called for a tsize of:" << tsize << "\n";
}

unsigned int DataLoader::hash_gen(int age_value)
{
	unsigned int hashKey;
	hashKey = age_value%tsize;
	return hashKey;
	cout<<"hash_gen function called \n";
}

void DataLoader::DataLoaderable_add(char *new_name, int new_age)
{ 
	int hashKey = hash_gen(new_age);
	Node * nodePtr;
	nodePtr = myArray[hashKey];
	if (myArray[hashKey] == 0) //adding first node in this bucket
	{
		myArray[hashKey] = new Node (new_name, new_age);
		cout<<"\nfirst node in list added with hash index of:" << hashKey<< "\n";
	}
	else
	{
		while (nodePtr ->next != 0)
		{
			//cout<<"while loop in add function called \n";
			nodePtr = nodePtr -> next;
			if(nodePtr ->name == new_name) //prevents duplication
			{
				return;
			}
		}
		nodePtr = new Node(new_name, new_age);
	}
}

void DataLoader::DataLoaderable_display()
{
	for (int i = 0; i < tsize; i++)
	{
		cout<<myArray[i];
		if (myArray[i] != 0)
		{
			Node * nodePtr;
			nodePtr = myArray[i];
			cout << "\nBucket "<< i <<": ";
			while (nodePtr ->name != 0)
			{
				int j;
				j = 0;
				while (nodePtr->name[j] != 0)
				{
					cout<<nodePtr->name[j];
					j++;
				}
				cout << " " << nodePtr ->age << " \n";
				nodePtr = nodePtr -> next;
				//cout<<"first while loop entered in display \n";
			}
			//cout<<"if loop entered in display function \n"; 
		}
	}
	//cout<<"DataLoaderable_display function called \n";
}
/*
void DataLoader::DataLoaderable_delete(char *name, int age)
{
	int hashKey =hash_gen(age);
	Node * nodePtr;
	Node * prevPtr;
	int num = 1;
	nodePtr = myArray[hashKey];
	while (nodePtr ->name != name)
	{
		prevPtr = nodePtr;
		nodePtr = nodePtr->next;
		num++;
	}
	if (nodePtr -> next == 0) //deleting last node
	{
		prevPtr = 0;
		delete nodePtr;
	}
	else if(num == 1) //deleting first node
	{ //not sure if this is right
		myArray[hashKey] = nodePtr -> next; //might be nodePtr
		delete nodePtr;
	}
	else
	{
		prevPtr ->next = nodePtr ->next;
	}
}
*/

DataLoader::~DataLoader(void)
{
	for (int i = 0; i < tsize; i++)
	{
		while (myArray[i] != 0)
		{
			Node * tempPtr;
			tempPtr = myArray [i];
			myArray[i] = tempPtr ->next;
			delete tempPtr;
		}
	}
	delete [] myArray;
}