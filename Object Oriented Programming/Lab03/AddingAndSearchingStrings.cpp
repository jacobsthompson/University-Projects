#include <iostream>
#include <vector>
#include <string>

using namespace std;

//the purpose of this code is to take in words longer than 4 characters and store in a vector
//if a word smaller than 4 is inputted, the code prints out all words in the vector that have the same starting letters

int main(){
	vector<string> v;

	//take input
	string curr;
	cin >> curr;

	//loop til quit is inputted
	while(curr != "quit"){
		//if input has more than four characters store in vector v
		if(curr.length() >= 4){
			v.push_back(curr);
		} else {
			//if input has less than 4 characters, print all words in v that have the same first letters as the < 3 input
			for(int i = 0; i < v.size(); i++){
				//create a substring of the curr.length letters in v
				//if they match print
				if(v[i].substr(0,curr.length()) == curr){
					cout << v[i] << endl;
				}
			}
		}
		//take new input
		cin >> curr;
	}
	
	return 0;
}