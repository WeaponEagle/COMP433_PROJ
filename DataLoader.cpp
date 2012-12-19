#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "data_structure/DataLoader.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

void DataLoader::loadData(char *file_name){

}

unsigned int DataLoader::hash_gen(char* term)
{
	unsigned int hashKey;
	//cout<<"term: "<<term<<" ; strlen(term): "<<strlen(term)<<" \n";
	hashKey = strlen(term)%tsize;
	//cout<<"hash_gen function called: "<<hashKey<<" \n";
	return hashKey;
}

void DataLoader::add(char *term, int df)
{ 
	bool isExist = false;
	int hashKey = hash_gen(term);
	TermNode* TermNodePtr = new TermNode(term, df);

	cout << myArray[hashKey].size();
	for (int i=0; i< myArray[hashKey].size(); i++){
		if (strcmp(myArray[hashKey][i]->getTerm(),term) == 0){
			cout<<"same word exist, add posting for:"<<term<<endl;
			isExist = true;
		}
	}
	if(!(isExist)){
		myArray[hashKey].push_back(TermNodePtr);
	}
}

void DataLoader::display()
{
	for( map<int, vector<TermNode*>>::iterator iter = myArray.begin(); iter != myArray.end(); ++iter ) {
	   vector<TermNode*> tempVec = (*iter).second;
	   int Key = (*iter).first;
	   cout << Key;
	   for (unsigned i = 0; i < tempVec.size(); i++) {
		   TermNode* node = tempVec[i];
		   cout << " " << node->getTerm();
	   }
	   cout << endl;
	}
	cout<<"DataLoaderable_display function called \n";
}