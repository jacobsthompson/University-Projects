#include <iostream>
#include <string>
#include <vector>

using namespace std;

//the purpose of this code is to sort words by length into a vector of string vectors

int main(){
	//make a vector that holds 10 vector of strings 
	vector<string> v[10];

	//input a word
	string input;
	cout << "Enter the input: ";
	cin >> input;

	while(input != "quit"){
		//push back the word into v based on how many letters input has
		//aka input.length = 6, store in V[6-1] (to account for 0-9)
		v[input.length()-1].push_back(input);
		//take in new input
		cout << "Enter the input: ";
		cin >> input;
	}

	//loop through all 10 vectors
	for(int i = 0; i < 10; i++){
		//print all words in each vector
		for(int j = 0; j < v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}