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
	/*
	DataLoader* loader = new DataLoader();
	//building dummy data
	Posting* test_po3 = new Posting(1,3,NULL);
	Posting* test_po2 = new Posting(1,2,test_po3);
	Posting* test_po1 = new Posting(1,1,test_po2);
	char* test_str1 = "test3"; 
	TermNode* test_node1 = new TermNode(test_str1,2,test_po1);
	//loader->addTermNode(test_node1);
	loader->put(50,"test");
	//demo function: from Dataloader -> TermNode -> posting
	cout<<"Node:"<<test_node1->getTerm()<<endl;
	Posting* post = test_node1->getPosting();
	do{
		cout<<"	Posting - getDocid:"<<post->getDocumentId()<<"; getTF:"<<post->getTermFrequency()<<endl;
		post = post->next();
	}while(post != NULL);
	*/
	//  the default class constructor
    DataLoader invFile; //bucket size is 10

   

// Test1: add data to invFile 
    /*invFile.add("David", 52); // add data to bucket 2 since hash value is 2
	invFile.add("Davod", 52); // add data to bucket 2 since hash value is 2
	invFile.add("David", 53); // add data to bucket 2 since hash value is 2
	invFile.add("Davod", 52); // add data to bucket 2 since hash value is 2
	invFile.add("David2", 52); // add data to bucket 2 since hash value is 2
	invFile.add("Goliath", 45); // add data to bucket 5 since hash value is 5
	invFile.add("Alan", 31);   // add data to bucket 1 since hash value is 1
	*/
cout << "\nTest 1: Printing Hash table with default bucket size :\n" ; 
	
	//system("pause");
	
	invFile.loadData("data/InvFile.txt");

	//cout<<endl<<"************ PRINT ALL RECORDS IN INV FILE ******************"<<endl<<endl;
	//invFile.display();
	cout<<endl<<"************ SOME TESTING FOR FINDTERM() ******************"<<endl<<endl;
	char* termA = "aU";
	cout<<endl<<"find term:"<<termA<<endl;
	TermNode* node = invFile.findTerm(termA);
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
	node = invFile.findTerm(termB);
	if (node != NULL){
		cout<<node->getTerm()<<" is found."<<endl;
	}else{
		cout<<termB<<" is not found."<<endl;
	}

	VSMRetrieval vsmRetrieval(&invFile);
	vsmRetrieval.retrieve("aU");

	system("pause");

	return 0;
}
