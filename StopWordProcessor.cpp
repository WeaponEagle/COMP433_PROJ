#include "StopWordProcessor.h"
#include <map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>

StopWordProcessor::StopWordProcessor(std::map<std::string, std::string> stopWordList)
{
	this->words = stopWordList;
}


std::string StopWordProcessor::processQuery(std::string query)
{
	// Split query
	std::istringstream stringStream(query);
	std::istream_iterator<std::string> begin(stringStream), end;
	std::vector<std::string> tokens(begin, end);

	// Loop tokens
	for (int i = 0; i < tokens.size(); i++) {
		// check if token is in list, 
		// del stem word
		if (this->words.count(tokens[i]) > 0) {
			tokens[i] = "";
		}
	}

	std::string stemmedQuery = "";
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] != "") {
			stemmedQuery += tokens[i];
			if (i != tokens.size() - 1) {
				stemmedQuery += " ";
			}
		}
	}
	return stemmedQuery;
}
