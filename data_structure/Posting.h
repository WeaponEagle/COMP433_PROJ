class Posting
{
public:
	Posting(int docid, int freq);
	
	virtual int getDocumentId();
	virtual int getTermFrequency();
	//virtual Posting* next();

private:
	int docid;
	int freq;
	//Posting* nextNode;

};