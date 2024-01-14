#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int wordtotal = 0;
	string word;
	
	ifstream txt("words.txt");

	while(txt >> word){
		//cout << word << endl;
		wordtotal++;
	}

	txt.close();

	cout << wordtotal << endl;
	
	return 0;
}