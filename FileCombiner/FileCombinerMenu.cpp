#include <iostream>
#include "FileCombiner.h"
#include "FileCombinerMenu.h"

void FileCombinerMenu::startMenu()
{
	while (currentOption != Select::SELECT_QUIT)
	{
		reUserSelection();
		executeSelection();
	}
	std::cout << "Program finished." << std::endl;
}

void FileCombinerMenu::executeSelection()
{
	std::string tmp;

	switch (currentOption)
	{
	case Select::SELECT_NONE:
		break;
	case Select::SELECT_ADD_FILES:
		addFiles(tmp);
		break;
	case Select::SELECT_DEFINE_DESTINATION:
		setDestination();
		break;
	case Select::SELECT_COMBINE_FILES:
		combineFiles();
		break;
	case Select::SELECT_QUIT:
		break;
	default:
		currentOption = Select::SELECT_NONE;
		break;
	}
}


void FileCombinerMenu::addFiles(std::string& tmp)
{
	while (tmp != "#")
	{
		std::cout << "Input a path or type # to exit to main menu: ";
		std::cin >> tmp;
		if (tmp != "#") paths.push_back(tmp);
	}
}

void FileCombinerMenu::setDestination(){
	std::cout << "Input a destination for the file: " << std::endl;
	std::cin >> this->destPath;
}

void FileCombinerMenu::combineFiles() {
	FileCombiner::combineFiles(paths, destPath);
}

void FileCombinerMenu::reUserSelection()
{
	int selection{ 0 };
	std::cout << "Please select an option of the following\n->" << static_cast<int>(Select::SELECT_ADD_FILES) << ": To add files." << std::endl;
	std::cout << "->" << static_cast<int>(Select::SELECT_DEFINE_DESTINATION) << ": to select destination path." << std::endl;
	std::cout << "->" << static_cast<int>(Select::SELECT_COMBINE_FILES) << ": to combine the files.\n->" <<
		static_cast<int>(Select::SELECT_QUIT) << ": to quit the program." << std::endl;
	std::cin >> selection;
	currentOption = static_cast<Select>(selection);
}
