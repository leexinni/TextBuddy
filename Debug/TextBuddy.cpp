#include <iostream>
#include <sstream>

#include "TextBuddy.h"

//constructor to initialise the name of file
TextBuddy::TextBuddy(string name) {
	nameOfFile = name;
}

//This method when called returns the number of lines of inputs stored
//in private vector of string 'userInputs'
int TextBuddy::getNumOfLines() {
	return userInputs.size();
}

//This method sorts the existing inputs stored in private vector alphabetically
void TextBuddy::sort() {
	std::sort (userInputs.begin(), userInputs.end());
	
	saveFile(nameOfFile);
	
	return;
}

//This method takes in a word input by the user.
//searches the vector stored privately 
//returns the lines which the words are found in the same format as the display function
string TextBuddy::search(string word) {
	
	ostringstream oss;

	for (int i = 0; i < getNumOfLines(); i++) {
		if (userInputs[i].find(word) < userInputs[i].size()) {//found word in string
			oss << endl << i+1 << ". " << userInputs[i] << endl;
		}
	}
	string out = oss.str();
	
	saveFile(nameOfFile);
	
	return out;
}

//This method deletes all the data stored in the file
//file becomes empty after clearing
void TextBuddy::clear() {
	userInputs.clear();
	cout << "\nall content deleted from " << nameOfFile << endl;

	saveFile(nameOfFile);

	return;
}

//This method delete a single line input
//user will input the line number
//this method assumes that the input number is valid
void TextBuddy::deleteAnInput(int number) {

	vector<string>::iterator iter = userInputs.begin();
	while (number > 1) {
		iter++;
		number--;
	}
	cout << "\ndeleted from " << nameOfFile << ": \"" << *iter << "\"\n";
	userInputs.erase(iter);

	saveFile(nameOfFile);

	return;
}

//This method adds line the user inputs to the end of the file
//assumes that user input is only 1 line
void TextBuddy::addToFile(string userInput) {

	userInput = userInput.substr(userInput.find_first_not_of(" "));

	userInputs.push_back(userInput);

	cout << "\nadded to " << nameOfFile << ": \"" << userInput << "\"\n";
	
	saveFile(nameOfFile);
	
	return;
}

//This method prints out everything that is stored, numbered from 1
string TextBuddy::display() {

	if (userInputs.empty()) {
		cout << endl << nameOfFile << " is empty\n";
	}
	else {
		vector<string>::iterator iter = userInputs.begin();
		
		ostringstream oss;

		int i = 0;
		while (iter != userInputs.end()){
			i++;
			oss << endl << i << ". " << *iter << endl;
			iter++;
		}

		string lines = oss.str();
		cout << lines;
		return lines;
	}
	
}

//This method saves all the existing stored data in a file
//this is implemented after every change is made by user
//change includes the add, delete, clear methods
void TextBuddy::saveFile(string name) {
	fstream aFile(name);
	ostringstream oss;

	vector<string>::iterator iter = userInputs.begin();

	for (int i = 0; i < getNumOfLines(); i++) {
		oss << i + 1 << ". " << *iter << endl << endl;
		iter++;
	}

	string out = oss.str();
	aFile << out;
	aFile.close();

	return;
}

//This method takes in the command line from the user and processes it
//according to what functions the user wants to accomplish
void TextBuddy::executeCommand(string command) {
	if (command == "exit") {
		return;
	}
	else if (command == "add") {
		string input;
		getline(cin, input);
		addToFile(input);
	}
	else if (command == "display") {
		display();
	}
	else if (command == "delete") {
		int number;
		cin >> number; 
		deleteAnInput(number);
	}
	else if (command == "clear") {
		clear();
	}
	else if (command == "sort") {
		sort();
	}
	else if (command == "search") {
		string word;
		getline(cin, word);
		cout << search(word);
	}

	return;
}

int main(int argc, char* argv[]) {

	//invalid number of arguments
	//tell user how to run the program
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <NAMEOFFILE>" << endl;

		return 0;
	}
	else {
		//print the welcome text
		cout << "\nWelcome to TextBuddy. " << argv[1] << " is ready for use" << endl;
		
		TextBuddy userInput(argv[1]);

		string command;

		do {
			cout << "\ncommand: ";
			cin >> command;
			userInput.executeCommand(command);
		} while (command != "exit");

		return 0;
	}
}