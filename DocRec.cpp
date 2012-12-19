#include "DocRec.h"

DocRec::DocRec(int docid, int doclen, std::string status, std::string docName, std::string docPath){
	this->docid = docid;
	this->doclen = doclen;
	this->status = status;
	this->docName = docName;
	this->docPath = docPath;
}
	
void DocRec::setDocLen(double doclen){
	this->doclen = doclen;
}
void DocRec::setStatus(std::string status){
	this->status = status;
}
void DocRec::setDocName(std::string docName){
	this->docName = docName;
}
void DocRec::setDocPath(std::string docPath){
	this->docPath = docPath;
}

double DocRec::getDocLen(){
	return this->doclen;
}
std::string DocRec::getStatus(){
	return this->status;
}
std::string DocRec::getDocName(){
	return this->docName;
}
std::string DocRec::getDocPath(){
	return this->docPath;
}