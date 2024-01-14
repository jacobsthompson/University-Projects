#include <iostream>
#include <string>
#include <vector>

using namespace std;

//the purpose of this code is to input a bunch of strings, and then when a single letter is inputted
//output all strings in vector that have that letter in it

int main(){
	//create 2 vectors for storing the words
	vector<string> v;
	//same vector but will be changed to uppercase
	vector<string> vupper;

	//take string input
	string input;
	cin >> input;

	//loop until the input string is 1 character or less
	while(input.length() > 1){
		//turn input into all uppercase version
		string temp;
		for(int i = 0; i < input.length(); i++){
			temp+=toupper(input[i]);
		}

		//store word in v, and uppercase version in vupper
		v.push_back(input);
		vupper.push_back(temp);
		//take new input
		cin >> input;
	}

	//the last input will be one character, stored in letter
	char letter = input[0];

	//loop through all words in vupper
	for(int i = 0; i < vupper.size(); i++){
		//check if the uppercase letter is found in the string
		if(vupper[i].find(toupper(letter)) != string::npos){
			//if so, print
			cout << v[i] << endl;
		} 
	}
	
	return 0;
}