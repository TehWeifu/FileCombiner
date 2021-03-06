#include <iostream>
#include <algorithm>
#include <iterator>

#include "FileCombiner.h"

std::ofstream FileCombiner::combineFiles(std::vector<std::string> files, std::string destination) {
	std::ofstream combinedFile{destination, std::ios::app};
	if (!combinedFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}

	//for (auto path : files)
	//{
	//	std::ifstream tempFile{ path, std::ios::in };

	//	if (!tempFile) continue;

	//	std::copy(tempFile.)
	//}

	std::ostream_iterator<std::string> output{ std::cout, "\n" };
	std::copy(files.begin(), files.end(), output);

	combinedFile.close();
	return combinedFile;
}