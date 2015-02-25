#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H

#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>

using namespace std;

//@author Lee Xin Ni
//Class used for storing user input data and manipulating the data
//manipulation is done through accessing the methods
class TextBuddy {
private:
	string nameOfFile;
	vector<string> userInputs;

public:
	TextBuddy(string);

	int getNumOfLines();

	void addToFile(string);

	string display();

	void deleteAnInput(int);

	void clear();

	void saveFile(string);

	void executeCommand(string);

	void sort();

	string search(string);
};


#endif