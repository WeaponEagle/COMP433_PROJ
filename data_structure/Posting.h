class Posting
{
public:
	Posting(int docid, int freq);
	virtual int getDocumentId();
	virtual int getTermFrequency();

private:
	int docid;
	int freq;
};