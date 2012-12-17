
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structure/DataLoader.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

DataLoader::DataLoader(void)
	:tsize(10)
{
	myArray = new TermNode * [10];
	for (int i = 0; i < 10; i++)
		myArray [i] = 0;
	cout<<"Default Constructor Called \n";
}

DataLoader::DataLoader(int tsize)
	:tsize(tsize)
{
	myArray = new TermNode * [tsize];
	for (int i = 0; i < tsize; i++)
		myArray[i] = 0; 
	cout<<"Constructor Called for a tsize of:" << tsize << "\n";


	//std::map<int, TermNode*> hashtable;
	//TermNode* termNode = hashtable[8];
	//termNode->add(new TermNode());
}

unsigned int DataLoader::hash_gen(char* term)
{
	unsigned int hashKey;
	//cout<<"term: "<<term<<" ; strlen(term): "<<strlen(term)<<" \n";
	hashKey = strlen(term)%tsize;
	//cout<<"hash_gen function called: "<<hashKey<<" \n";
	return hashKey;
}

void DataLoader::DataLoaderable_add(char *term, int df)
{ 
	int hashKey = hash_gen(term);
	TermNode * TermNodePtr;
	TermNodePtr = myArray[hashKey];
	if (myArray[hashKey] == NULL) //adding first TermNode in this bucket
	{
		myArray[hashKey] = new TermNode (term, df);
		cout<<"first TermNode in list - ";
		cout<<"added termnode:"<<myArray[hashKey]->getDocumentFrequency()<<myArray[hashKey]->getTerm()<<endl<<endl;
		//system("pause");
	}
	else
	{
		while (TermNodePtr->next() != 0){
			cout<<TermNodePtr->getTerm()<<";"<<term<<";test cmp str:"<<std::strcmp(TermNodePtr->getTerm(),term)<<endl;
			if(std::strcmp(TermNodePtr->getTerm(),term) == 0) //prevents duplication
			{
				cout<<"same word exist, add posting for:"<<term<<endl;
				return;
			}
			TermNodePtr = TermNodePtr->next();
		}
		if(std::strcmp(TermNodePtr->getTerm(),term) == 0) //prevents duplication
		{
			cout<<"same word exist, add posting for:"<<term<<endl;
			return;
		}
		cout<<"bucket have node, add chaining:"<<TermNodePtr->getDocumentFrequency()<<TermNodePtr->getTerm()<<endl<<endl;
		TermNode* TermNodePtr2 = new TermNode(term, df);
		TermNodePtr->add(TermNodePtr2);
	}
	
}

void DataLoader::DataLoaderable_display()
{
	for (int i = 0; i < tsize; i++)
	{
		//cout<<myArray[i];
		if (myArray[i] != 0)
		{
			TermNode * TermNodePtr;
			TermNodePtr = myArray[i];
			cout << "\nBucket "<< i <<": \n";
			do{
				cout<<"	Term - string:"<<TermNodePtr->getTerm()<<"; getDF:"<<TermNodePtr->getDocumentFrequency()<<endl;
				TermNodePtr = TermNodePtr->next();
			}while(TermNodePtr != 0);
		}
	}
	cout<<"DataLoaderable_display function called \n";
}
/*
void DataLoader::DataLoaderable_delete(char *name, int age)
{
	int hashKey =hash_gen(age);
	TermNode * TermNodePtr;
	TermNode * prevPtr;
	int num = 1;
	TermNodePtr = myArray[hashKey];
	while (TermNodePtr->getTerm() != name)
	{
		prevPtr = TermNodePtr;
		TermNodePtr = TermNodePtr->next;
		num++;
	}
	if (TermNodePtr ->next() == 0) //deleting last TermNode
	{
		prevPtr = 0;
		delete TermNodePtr;
	}
	else if(num == 1) //deleting first TermNode
	{ //not sure if this is right
		myArray[hashKey] = TermNodePtr ->next(); //might be TermNodePtr
		delete TermNodePtr;
	}
	else
	{
		prevPtr->next() = TermNodePtr->next();
	}
}
*/

DataLoader::~DataLoader(void)
{
	for (int i = 0; i < tsize; i++)
	{
		while (myArray[i] != 0)
		{
			TermNode * tempPtr;
			tempPtr = myArray [i];
			myArray[i] = tempPtr->next();
			delete tempPtr;
		}
	}
	delete [] myArray;
}