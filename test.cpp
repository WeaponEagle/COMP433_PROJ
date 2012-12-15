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
    DataLoader htable; //bucket size is 10

    
    //  the other class constructor
    DataLoader hashtable(7); //bucket size is 7
 

// Test1: add data to htable 
       htable.DataLoaderable_add("David", 52); // add data to bucket 2 since hash value is 2
	htable.DataLoaderable_add("Goliath", 45); // add data to bucket 5 since hash value is 5
	htable.DataLoaderable_add("Alan", 31);   // add data to bucket 1 since hash value is 1
cout << "\nTest 1: Printing Hash table with default bucket size :\n" ; 
	htable.DataLoaderable_display();

// Test2: add data to hashtable
 hashtable.DataLoaderable_add("David", 52); // add data to bucket 3 since hash value is 3
	hashtable.DataLoaderable_add("Goliath", 46); // add data to bucket 4 since hash value is 4
	hashtable.DataLoaderable_add("Alan", 33);   // add data to bucket 5 since hash value is 5
cout << "\nTest 2: Printing Hash table with bucket size 7 : \n" ; 
	hashtable.DataLoaderable_display();

// Test3: delete data from htable
      // htable.DataLoaderable_delete("David", 52); // delete data from bucket 2 since hash value is 2
cout << "\nTest 3: Printing Hash table with default bucket size :\n" ; 
	htable.DataLoaderable_display();

//  Test4: delete data from hashtable
       //hashtable.DataLoaderable_delete("David", 52); // delete data from bucket 3 since hash value is 3
cout << "\nTest 4: Printing Hash table with bucket size 7 : \n" ; 
	hashtable.DataLoaderable_display();

// Test5: add duplicate data to htable
       htable.DataLoaderable_add("Alan", 31);   // data is not added since it already exists
cout << "\nTest 5: Printing Hash table with default bucket size :\n" ; 
	htable.DataLoaderable_display();

// Test6: add duplicate data to hashtable
	hashtable.DataLoaderable_add("Alan", 33);   // data is not added since it already exists
cout << "\nTest 6: Printing Hash table with bucket size 7 : \n" ; 
	hashtable.DataLoaderable_display();

// Test7: adds multiple data items to same bucket in htable
	htable.DataLoaderable_add("Tom", 65); // add data to bucket 5 since hash value is 5
	htable.DataLoaderable_add("Alice", 51);   // add data to bucket 1 since hash value is 1
	htable.DataLoaderable_add("Ben", 25); // add data to bucket 5 since hash value is 5
	htable.DataLoaderable_add("Amy", 21);   // add data to bucket 1 since hash value is 1
cout << "\nTest 7: Printing Hash table with default bucket size :\n" ; //adds multiple data items to same bucket
	htable.DataLoaderable_display();


// Test8: adds multiple data items to same bucket in hashtable
	hashtable.DataLoaderable_add("Ricky", 18); // add data to bucket 4 since hash value is 4
	hashtable.DataLoaderable_add("Adrian", 19);   // add data to bucket 5 since hash value is 5
	hashtable.DataLoaderable_add("Jack", 25); // add data to bucket 4 since hash value is 4
	hashtable.DataLoaderable_add("Grace", 26);   // add data to bucket 5 since hash value is 5
cout << "\nTest 8: Printing Hash table with bucket size 7 : \n" ;  //adds multiple data items to same bucket
	hashtable.DataLoaderable_display();

// Test9: deletes data from buckets with multiple data items in htable
	//htable.DataLoaderable_delete("Ben", 25); // delete data from bucket 5 since hash value is 5
	//htable.DataLoaderable_delete("Amy", 21);   // delete data from bucket 1 since hash value is 1
cout << "\nTest 9: Printing Hash table with default bucket size :\n" ; //deletes data from buckets with multiple data items
	htable.DataLoaderable_display();

// Test10: deletes data from buckets with multiple data items in hashtable
	//hashtable.DataLoaderable_delete("Jack", 25); // delete data from bucket 4 since hash value is 4
	//hashtable.DataLoaderable_delete("Grace", 26);   // delete data from bucket 5 since hash value is 5
cout << "\nTest 10: Printing Hash table with bucket size 7 : \n" ;  //deletes data from buckets with multiple data items
	hashtable.DataLoaderable_display();

	system("pause");
	return 0;
}
