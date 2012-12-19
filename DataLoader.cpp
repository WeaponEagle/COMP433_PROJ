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
	FILE * fp = fopen(file_name, "rb");
	char lineBuffer[10000];

	if (fp == NULL) {
		printf("Aborted: file not found for <%s>\r\n",file_name);
		return;
	}
	while ( ! feof (fp) )
     {
       if ( fgets (lineBuffer , 10000 , fp) != NULL )
		   //cout<<lineBuffer;
			invFileSingleLineProcess(lineBuffer);
     }
	//do {	
		//next = true;
		//if (fread(&c,1,1,fp) > 0) { // read a character
	//}while(1);	
};

void DataLoader::invFileSingleLineProcess(char* lineBuffer){
	//cout<<lineBuffer;
	char * token;
	char term[1000]; int df; //used by termnode
	int docid; int freq; //used by posting
	char * delim = ",";
	//token = strtok(lineBuffer,":");
	token = strtok(lineBuffer,":");
	//cout<<"token:"<<token<<endl;
	sscanf(token,"%s %d",term,&df);
	//cout<<"get term & df: "<<term<<";"<<df<<endl;
	//cout<<"token:"<<token<<endl;
	TermNode* newTerm = new TermNode(strdup(term),df);
	
	token = strtok (NULL, delim);
	while(token != NULL)
	{
		//cout<<token<<endl;
		sscanf(token,"%d %d",&docid,&freq);
		//cout<<"get docid & freq: "<<docid<<";"<<freq<<endl;
		newTerm->addPosting(docid,freq);
		//system("pause");
		token = strtok (NULL, delim);	
	}  
	this->add(newTerm);

}

unsigned int DataLoader::hashGen(const char* term)
{
	unsigned int hashKey;
	//cout<<"term: "<<term<<" ; strlen(term): "<<strlen(term)<<" \n";
	hashKey = strlen(term)%tsize;
	//cout<<"hashGen function called: "<<hashKey<<" \n";
	return hashKey;
}

void DataLoader::add(TermNode* node)
{ 
	bool isExist = false;
	int hashKey = hashGen(node->getTerm());
	TermNode* result = this->findTerm(node->getTerm());
	if(result == NULL){
		invFile[hashKey].push_back(node);
	}
}

TermNode* DataLoader::findTerm(const char* term)
{
	int hashKey = hashGen(term);
	for (int i=0; i< invFile[hashKey].size(); i++){
		//cout<<invFile[hashKey][i]->getTerm()<<" and "<<term<<strcmp(invFile[hashKey][i]->getTerm(),term)<<endl;
		if (strcmp(invFile[hashKey][i]->getTerm(),term) == 0){
			//cout<<"same word exist for"<<invFile[hashKey][i]->getTerm()<<" and "<<term<<", error exist";
			return invFile[hashKey][i];
		}
	}
	return NULL;
};
	
void DataLoader::display()
{
	for( map<int, vector<TermNode*>>::iterator iter = invFile.begin(); iter != invFile.end(); ++iter ) {
	   vector<TermNode*> tempVec = (*iter).second;
	   int Key = (*iter).first;
	   cout << Key;
	   for (unsigned i = 0; i < tempVec.size(); i++) {
		   TermNode* node = tempVec[i];
		   cout<<"	term:" << node->getTerm() <<"	df:" << node->getDocumentFrequency() << " : "<<endl;
		   vector<Posting*> posting = node->getPosting();
		   for (unsigned j = 0; j < posting.size(); j++) {
			   cout<<"		docid:"<<posting[j]->getDocumentId()<<" ; freq:"<<posting[j]->getTermFrequency()<<endl;
		   }
	   }
	   cout << endl;
	}
	cout<<"DataLoaderable_display function called \n";
}

int DataLoader::getTotalDocuments(){
	return 10;	
}
double DataLoader::getDocumentLengthById(int docid){
	return 1;
}