#pragma once
#include <string>

class DocRec
{
public:
	DocRec(int docid, int doclen, std::string status, std::string docName, std::string docPath);
	double getDocLen();
	std::string getStatus();
	std::string getDocName();
	std::string getDocPath();
	void setDocLen(double doclen);
	void setStatus(std::string status);
	void setDocName(std::string docName);
	void setDocPath(std::string docPath);
	
private:
	int docid;
	double doclen;
	std::string status;
	std::string docName;
	std::string docPath;

};