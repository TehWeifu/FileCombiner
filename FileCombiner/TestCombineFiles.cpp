#include <vector>
#include <string>
#include "FileCombiner.h"
#include "FileCombinerMenu.h"
#include "jagpdf/api.h"

using namespace jag;

int main()
{
 //   pdf::Document doc(pdf::create_file("hello.pdf"));
 //   doc.page_start(597.6, 848.68);
 //   doc.page().canvas().text(50, 800, "Hello, world!");
 //   doc.page_end();
	//doc.page_start(597.6, 848.68);
	//doc.page().canvas().text(200, 600, "TZest!");
	//doc.page_end();
 //   doc.finalize();
	//FileCombinerMenu test;
	//test.startMenu();
	std::vector<std::string> testVec{ "FileCombiner.cpp", "TestCombineFiles.cpp" };
	FileCombiner::combineFiles(testVec, "");
	return 0;
}