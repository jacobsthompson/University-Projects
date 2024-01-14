#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("words.txt");
	string currLine;

	while(getline(input, currLine)){
		cout << currLine << endl;
	}

	input.close();
	
	return 0;
}