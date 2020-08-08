#pragma once

#include <vector>
#include <string>
#include "FileCombiner.h"

enum class Select {
	SELECT_NONE = 0, SELECT_ADD_FILES, SELECT_DEFINE_DESTINATION, SELECT_COMBINE_FILES, SELECT_QUIT
};

class FileCombinerMenu
{
public:
	FileCombinerMenu() = default;
	~FileCombinerMenu() = default;

	void startMenu();
	void executeSelection();
	void addFiles(std::string& tmp);
	void reUserSelection();
	void setDestination();
	void combineFiles();

private:
	Select currentOption{ Select::SELECT_NONE };
	std::vector<std::string> paths;
	std::string destPath{ "" };
	FileCombiner comb;
};