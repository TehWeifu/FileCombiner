#include <vector>
#include <string>

#include "FileCombiner.h"

int main()
{
	std::vector<std::string> testVec{ "FileCombiner.cpp", "TestCombineFiles.cpp" };
	FileCombiner::combineFiles(testVec, "test.txt");

	return 0;
}