#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataLoader.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

DataLoader::DataLoader(){
	this->hashSize = 13023973;
}
int DataLoader::getHashSize(){
	return this->hashSize;
}
void DataLoader::loadInvFile(char *file_name){
	FILE * fp = fopen(file_name, "rb");
	char lineBuffer[10000];
	if (fp == NULL) {
		printf("Aborted: file not found for <%s>\r\n",file_name);
		return;
	}
	//int i = 0;
	while ( ! feof (fp) )
	{
		if ( fgets (lineBuffer , 10000 , fp) != NULL )
			invFileSingleLineProcess(lineBuffer);
		//i++;
		//if (i%1000 == 0){
		//	cout<<"[i] = "<<i<<endl;
		//}
	}
};

void DataLoader::invFileSingleLineProcess(char* lineBuffer){
	char * token;
	char term[1000]; int df; //used by termnode
	int docid; int freq; //used by posting
	char * delim = ",";
	token = strtok(lineBuffer,":");
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

void DataLoader::loadDocRec(char *file_name){
	FILE * fp = fopen(file_name, "rb");
	char lineBuffer[10000];
	char* ptr = lineBuffer;
	if (fp == NULL) {
		printf("Aborted: file not found for <%s>\r\n",file_name);
		return;
	}

	int i=0;
	while ( ! feof (fp) )
	{
		if ( fgets (lineBuffer , 10000 , fp) != NULL ){
			int docid=0; int doclen=0; 

			char status_buf[100];
			char docName_buf[100];
			char docPath_buf[200];
			sscanf(ptr,"%d %d %s %s %s",&docid,&doclen,status_buf,docName_buf,docPath_buf);
			string status(status_buf); 
			string docName(docName_buf); 
			string docPath(docPath_buf); //used for document record
			DocRec* docrec = new DocRec(docid,doclen,status,docName,docPath);
			documentRecords.push_back(docrec);
			//cout<<"test:"<<documentRecords[i]->getDocName()<<" "<<endl;   i++;
			//system("pause");

		}
	}
};

void DataLoader::loadDocLen(char *file_name){
	FILE * fp = fopen(file_name, "rb");
	char lineBuffer[10000];
	if (fp == NULL) {
		printf("Aborted: file not found for <%s>\r\n",file_name);
		return;
	}
	int docid; double docLen;
	fgets (lineBuffer , 10000 , fp);
	while ( ! feof (fp) )
	{
		if ( fgets (lineBuffer , 10000 , fp) != NULL ){
			//cout<<"raw input:"<<lineBuffer<<" "<<endl; 
			sscanf(lineBuffer,"%d %lf",&docid,&docLen);
			//cout<<"before adding:"<<docid<<":"<<docLen<<" "<<endl; 
			documentRecords[docid]->setDocLen(docLen);
			//cout<<"call from obj:"<<docid<<":"<<documentRecords[docid]->getDocLen()<<" "<<endl; 
			//system("pause");
		}
	}
};


unsigned int DataLoader::hashGen(const char* term)
{
	//unsigned int hashKey;
	//cout<<"term: "<<term<<" ; strlen(term): "<<strlen(term)<<" \n";
	//hashKey = strlen(term)%this->hashSize;
	//cout<<"hashGen function called: "<<hashKey<<" \n";
	
	const char * t = term;
	int hashKey = 3;
	if (term == NULL) return 0;

	while (*t != '\0') {
		hashKey = (31*hashKey + 57*((int) (unsigned char) *t));
		if (hashKey < 0) hashKey = -1 * hashKey;
		hashKey = hashKey % this->getHashSize();
		t++;
	}
	
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
	return this->documentRecords.size();
}
DocRec* DataLoader::getDocumentRecordById(int docid){
	return this->documentRecords[docid];
}