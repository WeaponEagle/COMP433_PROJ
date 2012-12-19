#include <vector>
#include <map>
using namespace std;

class DocRec
{
public:
	DocRec(int docid, int doclen, string status, string docName, string filePath);
	
private:
	int docid;
	int doclen;
	string status;
	string docName;
	string filePath;

};