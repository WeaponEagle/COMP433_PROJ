#include "DataLoader.h"
#include "VSMRetrieval.h"

int main() {
	
    DataLoader dataLoader;
	dataLoader.loadInvFile("data/InvFile.txt");
	dataLoader.loadDocRec("data/file.txt");
	dataLoader.loadDocLen("data/InvFile.doc");
	
	VSMRetrieval vsmRetrieval(&dataLoader);
	vsmRetrieval.retrieve("aU");

	system("pause");

	return 0;
}
