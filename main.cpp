///////////////////////////////////////////////////////////////////////////////////////
//
// Author: Robert Luk
// Year: 2010
// Robert Luk (c) 2010 
//
// Interactive Retrieval using the Integrated Inverted Index Class:
// This software is made available only to students studying COMP433 (Information
// Retreieval). It should not be used or distributed without consent by the author.
//
////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#include "data_structure/DataLoader.h";
#include "retrieval/VSMRetrieval.h";

int main() {
	
    DataLoader dataLoader;

cout << "\nTest 1: Printing Hash table with default bucket size :\n" ; 
	
	//system("pause");
	
	dataLoader.loadInvFile("data/InvFile.txt");
	cout<<endl<<"************ TEST - DOCUMENT RECORD FILE ******************"<<endl<<endl;
	dataLoader.loadDocRec("data/file.txt");
	cout<<dataLoader.getTotalDocuments();
	//system("pause");
	cout<<endl<<"************ TEST - DOCUMENT RECORD FILE ******************"<<endl<<endl;
	dataLoader.loadDocLen("data/InvFile.doc");
	cout<<endl<<"************ PRINT ALL RECORDS IN INV FILE ******************"<<endl<<endl;
	//invFile.display();
	cout<<endl<<"************ SOME TESTING FOR FINDTERM() ******************"<<endl<<endl;
	char* termA = "aU";
	cout<<endl<<"find term:"<<termA<<endl;
	TermNode* node = dataLoader.findTerm(termA);
	if (node != NULL){
		cout<<node->getTerm()<<" is found."<<endl;
		cout<<"posting size:"<<node->getPosting().size()<<endl;
		
		for (int i=0; i < node->getPosting().size(); i++){
			cout<<"docid:"<<node->getPosting()[i]->getDocumentId()<<"; tf:"<<node->getPosting()[i]->getTermFrequency()<<endl;
		}

	}else{
		cout<<termA<<" is not found."<<endl;
	}
	
	char* termB = "ofpkwefpokw";
	cout<<endl<<"find term:"<<termB<<endl;
	node = dataLoader.findTerm(termB);
	if (node != NULL){
		cout<<node->getTerm()<<" is found."<<endl;
	}else{
		cout<<termB<<" is not found."<<endl;
	}

	VSMRetrieval vsmRetrieval(&dataLoader);
	vsmRetrieval.retrieve("aU");

	system("pause");

	return 0;
}
