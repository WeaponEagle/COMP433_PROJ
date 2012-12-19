#include "DataLoader.h"
#include "VSMRetrieval.h"
#include <time.h>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
    DataLoader dataLoader;
	clock_t begin_time = clock();
	cout << "Reading inverted file to RAM" << endl;
	dataLoader.loadInvFile("data/InvFile_.txt");
	std::cout<< "Time elapsed: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC<< " seconds"<< endl;

	cout << "Reading document length to RAM" << endl;
	begin_time = clock();
	dataLoader.loadDocRec("data/file.txt");
	dataLoader.loadDocLen("data/InvFile.doc");
	std::cout<< "Time elapsed: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC<< " seconds"<< endl;


	VSMRetrieval vsmRetrieval(&dataLoader);
	begin_time = clock();

	std::vector<std::string> list;
	std::string line;
	std::fstream queryFile("data/queryT");
	if (!queryFile.is_open()) throw "File not found";
	while (queryFile.good()) {
		//cout<<"hi"<<endl;
		getline(queryFile, line);
		list.push_back(line);
		//vsmRetrieval.retrieve(line);
	}
	queryFile.close();
	//cout<<list.size();
	for (int i = 0; i < list.size(); i++) {
		//cout<<list[i];
		vsmRetrieval.retrieve(list[i]);
	}

	/*
	if (fp == NULL) {
		printf("Aborted: file not found.");
		return;
	}
	while (!feof(fp))
	{
		if ( fgets (lineBuffer , 10000 , fp) != NULL ){
			vsmRetrieval.retrieve(lineBuffer);
		}
	}*/
	//vsmRetrieval.retrieve("aU");
	std::cout<< "Time elapsed: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC<< " seconds"<< endl;


	system("pause");

	return 0;
}
