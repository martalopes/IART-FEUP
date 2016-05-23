#include <cstdlib>
#include <iostream>
#include <string>

#include "Folders.h"

int main() {
	// https://www.rulequest.com/see5-unix.html
	std::string input = Folders::DATA_FOLDER + "input/ck";
	std::string options = "-X 10";

	//-b -g -w
	//-b -p
	//-b -p -w
	//-b
	//-b -w
	//-g
	//-p
	//-p -w
	//-w
	//-X 100
	//-X 10
	//noflags

	std::string output = Folders::DATA_FOLDER + "output/" + "\"" + options + "_results.txt\"";

	std::string cmd = "../c50/c5.0 -f " + input + " " + options + " > " + output;

	system(cmd.c_str());

	std::cout << "Done." << std::endl;

	return 0;
}


