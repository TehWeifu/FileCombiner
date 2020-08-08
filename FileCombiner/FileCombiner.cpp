#include <iostream>
#include <algorithm>
#include <iterator>
#include "jagpdf/api.h"
#include "FileCombiner.h"
#include <filesystem>

namespace fs = std::filesystem;
using namespace jag;

void FileCombiner::combineFiles(std::vector<std::string>& files) {
	if(files.empty()){
		std::cout << "No files provided, combining currentDirectory..." << std::endl;
		readFilesFromCurrentDirectory(files);
		std::for_each(files.begin(), files.end(), [](const auto& path) {std::cout << path << std::endl; });
	}
	if(currentDestinationPath.empty()) currentDestinationPath = files[0] + "_combined.txt";
	std::ofstream combinedFile{ currentDestinationPath, std::ios::app};
	if (!combinedFile) {
		std::cerr << "File could not be opened" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (auto path : files)
	{
		fs::directory_entry tmp(path);
		std::ifstream tempFile{ path, std::ios::in };
		if (!tempFile) continue;
		combinedFile << "------------------------------ " << tmp.path().filename().string() << " ------------------------------" << std::endl;
		while (tempFile.good() && tempFile.peek() != EOF)
		{
			combinedFile.put(tempFile.get());
		}
		combinedFile << "\r\n";
	}
	combinedFile.close();
}

void FileCombiner::readFilesFromCurrentDirectory(std::vector<std::string>& files)
{
	if (currentDirectory.empty()) currentDirectory = fs::current_path().string();
	for (const auto& entry : fs::directory_iterator(currentDirectory)) {
		if (entry.is_regular_file()) files.emplace_back(entry.path().string());
	}
}

void FileCombiner::setCurrentDirectory(const std::string& path)
{
	this->currentDirectory = path;
}

void FileCombiner::setDestinationPath(const std::string& path)
{
	this->currentDestinationPath = path;
}