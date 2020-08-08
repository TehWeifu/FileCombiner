#pragma once

#include <vector>
#include <string>
#include <fstream>

class FileCombiner
{
public:
	void combineFiles(std::vector<std::string>& paths);
	void setCurrentDirectory(const std::string& path);
	void setDestinationPath(const std::string& path);
	void readFilesFromCurrentDirectory(std::vector<std::string>& files);
private:
	std::string currentDirectory = "";
	std::string currentDestinationPath = "";

};