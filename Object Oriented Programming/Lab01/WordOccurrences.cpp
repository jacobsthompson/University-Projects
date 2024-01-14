#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int wordtotal = 0;
	ifstream txt("words.txt");
	string word;
	string wordtofind;

	cin >> wordtofind;

	//Capitalize word to be found
	int i = 0;
	while(wordtofind[i]){
		wordtofind[i] = toupper(wordtofind[i]);
		i++;
	}

	while(txt >> word){
		//Capitalize current word
		int j = 0;
		while(word[j]){
			word[j] = toupper(word[j]);
			j++;
		}

		cout << word << endl;

		//check if last character in word is NOT punctuation
		if(word[word.size()-1] >= 65 && word[word.size()-1] <= 90){
			if(word == wordtofind){
				wordtotal++;
			}
		} else {
			//compare current word minus the punctuation with the word to find
			if(word.substr(0,word.size()-1) == wordtofind){
				wordtotal++;
			}
		}
	}

	txt.close();

	cout << wordtotal << endl;
	
	return 0;
}