#pragma once
#include <string>
#include <map>

class StopWordProcessor
{
public:
	StopWordProcessor(std::map<std::string, std::string> stopWordList);
	std::string processQuery(std::string query);

private:
	std::map<std::string, std::string> words;
};

