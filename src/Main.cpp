#include <cstdlib>
#include <iostream>
#include <string>

#include "Folders.h"

using namespace std;

void clearscreen()
{
	cout << string( 100, '\n' );
}

void mainmenu(char choice[2]){
	clearscreen();
	cout << "Menu: \n"
			<< "1. Use training data set\n"
			<< "2. Use training and test data set\n"
			<< "3. Make a diagnosis\n"
			<< "4. Exit\n";

	cin >> choice;
}

void  menu1(char choice[2]){
	clearscreen();
	cout << "Which enhancements do you wish to use?\n"
			<< "1. No enhancements\n"
			<< "2. Boosting\n"
			<< "3. Winnowing\n"
			<< "4. Do not use global tree prunning\n"
			<< "5. Boosting and Winnowing\n"
			<< "6. Boosting, Winnowing and not using global tree prunning\n"
			<< "7. Go Back\n";
	cin >> choice;
}

void runframework(string file, string flags){
	string input = Folders::DATA_FOLDER + "input/" + file;
	string options = flags;

	string output = Folders::DATA_FOLDER + "output/" + "\"" + options + "_" + file + "_results.txt\"";

	string cmd = "../c50/c5.0 -f " + input + " " + options + " > " + output;

	system(cmd.c_str());

	cout << "Done." << endl;
}


void runpredframework(string file, string flags){
	string input = Folders::DATA_FOLDER + "input/" + file;
	string options = flags;

	string output = Folders::DATA_FOLDER + "outputPrediction/" + "\"" + options + "_" + file + "_results.txt\"";

	string cmd = "../prediction/a.out -f " + input + " " + options + " > " + output;

	system(cmd.c_str());

	cout << "Done." << endl;
}

int fmwrkmenu(){
	while(1){
		char choice[2];

		mainmenu(choice);

		if(choice[0] == '1'){

			menu1(choice);

			if(choice[0] == '1'){
				runframework("ck2"," ");
				}
			else if(choice[0] == '2'){
				runframework("ck2","-b");
				}
			else if(choice[0] == '3'){
				runframework("ck2","-w");
				}
			else if(choice[0] == '4'){
				runframework("ck2","-g");
				}
			else if(choice[0] == '5'){
				runframework("ck2","-b -w");
				}
			else if(choice[0] == '6'){
				runframework("ck2","-b -w -g");
				}
			else if(choice[0] == '7'){
				fmwrkmenu();
				}
		}
		else if(choice[0] == '2'){

			menu1(choice);

			if(choice[0] == '1'){
				runframework("ck"," ");
			}
			else if(choice[0] == '2'){
				runframework("ck","-b");
			}
			else if(choice[0] == '3'){
				runframework("ck","-w");
			}
			else if(choice[0] == '4'){
				runframework("ck","-g");
			}
			else if(choice[0] == '5'){
				runframework("ck","-b -w");
			}
			else if(choice[0] == '6'){
				runframework("ck","-b -w -g");
			}
			else if(choice[0] == '7'){
				fmwrkmenu();
			}
		}
		else if (choice[0] == '3'){
			string filename;
			cout << "Which file do you want to use? \n";
			cin >> filename;
			runpredframework(filename, " ");
		}
		else if (choice[0] == '4'){
			return 1;
		}
	}
}

int main() {
	fmwrkmenu();
	cout << "Exiting framework..." << endl;
	return 0;
}


