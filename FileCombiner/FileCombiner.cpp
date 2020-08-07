#include <iostream>
#include <algorithm>
#include <iterator>
#include "jagpdf/api.h"
#include "FileCombiner.h"

using namespace jag;

void FileCombiner::combineFiles(std::vector<std::string> files, std::string destination) {
	if(files.empty()){
		std::cerr << "No files to combine." << std::endl;
		return;
	}
	if(destination.empty()) destination = files[0] + ".pdf";
	std::ofstream combinedFile{destination, std::ios::app};
	if (!combinedFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto path : files)
	{
		std::ifstream tempFile{ path, std::ios::in };
		if (!tempFile) continue;

		while (tempFile.good() && tempFile.peek() != EOF)
		{
			combinedFile.put(tempFile.get());
		}
		combinedFile << "\r\n";
	}
	//std::ostream_iterator<std::string> output{ std::cout, "\n" };
	//std::copy(files.begin(), files.end(), output);
	combinedFile.close();
}