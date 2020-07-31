#pragma once

#include <vector>
#include <string>
#include <fstream>

class FileCombiner
{
public:
	static std::ofstream combineFiles(std::vector<std::string>, std::string);

};