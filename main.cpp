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
	dataLoader.loadInvFile("data/InvFile.txt");
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
		getline(queryFile, line);
		list.push_back(line);
	}
	queryFile.close();

	ofstream ofs("data/queryT_files/result.txt");
	for (int i = 0; i < list.size(); i++) {
		vsmRetrieval.retrieve(list[i], ofs);
	}
	ofs.close();
	std::cout<< "Time elapsed: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC<< " seconds"<< endl;


	system("pause");

	return 0;
}
