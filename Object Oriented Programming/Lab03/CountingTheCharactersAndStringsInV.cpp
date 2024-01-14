#include <iostream>
#include <string>
#include <vector>

using namespace std;

//the purpose of this code is the same as VectorOfVectorsOfStrings execpt this code outputs the total characters and strings in each vector

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

	//loop through all vectors
	for(int i = 0; i < 10; i++){
		//if there are strings in v[i]
		if(v[i].size() > 0){
			//add up all characters in vector and store total
			int totalchars = 0;
			for(int j = 0; j < v[i].size(); j++){
				totalchars += v[i][j].length();
			}
			//print total characters and then number of elements
			cout << totalchars << " " << v[i].size() << endl;
		}
	}
	
	return 0;
}