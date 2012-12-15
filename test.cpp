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

int main() {
	
	DataLoader* loader = new DataLoader();
	//building dummy data
	Posting* test_po3 = new Posting(1,3,NULL);
	Posting* test_po2 = new Posting(1,2,test_po3);
	Posting* test_po1 = new Posting(1,1,test_po2);
	char* test_str1 = "test3"; 
	TermNode* test_node1 = new TermNode(test_str1,2,test_po1);
	loader->addTermNode(test_node1);

	//demo function: from Dataloader -> TermNode -> posting
	cout<<"Node:"<<test_node1->getTerm()<<endl;
	Posting* post = test_node1->getPosting();
	do{
		cout<<"	Posting - getDocid:"<<post->getDocumentId()<<"; getTF:"<<post->getTermFrequency()<<endl;
		post = post->next();
	}while(post != NULL);
	system("pause");
	return 0;
}
