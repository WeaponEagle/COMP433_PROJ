//
//  VSMSeachEngine.cpp
//  comp433
//
//  Created by Jimmy Au on 15/12/12.
//  Copyright (c) 2012 ECJMT. All rights reserved.
//

#include "VSMRetrieval.h"
#include "RetrievedDocument.h"
#include "DataLoader.h"
#include "stem.h"

#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>

int MAX_NUMBER_OF_RESULTS = 1000;

// Used for sorting
struct ResultComparator {
    bool operator ()(RetrievedDocument *a, RetrievedDocument *b) const {
        return (a->similarity > b->similarity);
    }
};


/**
 * Constructor
 */
VSMRetrieval::VSMRetrieval(DataLoader *dataLoader)
{
    this->dataLoader = dataLoader;
}


/**
 * Retrieve results
 */
void VSMRetrieval::retrieve(std::string query)
{
	stemmer stm;

    // Split query, putting all the tokens into a vector
    std::istringstream ss(query);
    std::istream_iterator<std::string> begin(ss), end;
    std::vector<std::string> tokens(begin, end);
    
    // Query Length
    int numberOfTokens = (int) tokens.size();
    double queryLength = sqrt((double)numberOfTokens);
    
    // Find term
    std::map<int, RetrievedDocument> results;
    for (int i = 0; i < numberOfTokens; i++) {        
        std::string term = tokens[i];
		stm.Stem(term);
        TermNode *termNode = dataLoader->findTerm(term.c_str());
		if (!termNode) {
			continue;
		}
        std::vector<Posting*> postings = termNode->getPosting();
        
        // Use this term's all postings to calculate TFIDF score
        for (int j = 0; j < postings.size(); j++) {
            Posting *posting = postings[j];
            int documentId = posting->getDocumentId();
            RetrievedDocument *retrievedDocument = &results[documentId];
            retrievedDocument->documentId = documentId;
            retrievedDocument->similarity += posting->getTermFrequency() * (log((double)dataLoader->getTotalDocuments()) / termNode->getDocumentFrequency()); // TF * IDF
        }
    }
    
    // Vector storing references only
    std::vector<RetrievedDocument*> resultList;
    for(std::map<int, RetrievedDocument>::iterator it = results.begin(); it != results.end(); it++) {
    	resultList.push_back(&(it->second));
    }
    
    // Normalize
    int size = (int) resultList.size();
    for (int i = 0; i < size; i++) {
        RetrievedDocument *retrievedDocument = resultList[i];
		double documentLength = dataLoader->getDocumentRecordById(retrievedDocument->documentId)->getDocLen();
        retrievedDocument->similarity /= (queryLength * documentLength);
    }
    
    // Sort results
    std::sort(resultList.begin(), resultList.end(), ResultComparator());
    ofstream ofs("data/vsm_queryT.txt");
    // Print maximum top 1000 results
    size = std::min(MAX_NUMBER_OF_RESULTS, (int) resultList.size());
    for (int i = 0; i < size; i++) {
        RetrievedDocument *document = resultList[i];
        std::cout << "Rank " << (i+1) << ": " << "Document ID: " << document->documentId << ", Similarity score: " << document->similarity << std::endl;
    }
	ofs.close();

	std::cout << "======" << std::endl << std::endl;
    
}
