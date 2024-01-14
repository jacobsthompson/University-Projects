#include <iostream>

using namespace std;

//this function recurvely turns a integer and cout's it in it's binary form
void binary(int x){
	if(x > 1){ binary(x/2); }
	cout << x % 2;
}

int main(){
	//take in positive input int
	int input;
	cin >> input;

	//while loop to continue outputting the values until negative number is inputted
	while(input >= 0){
		//output integer in hex form
		cout << hex << input << endl;
		//call binary function to output in binary form
		binary(input);
		cout << endl;
		//take in new input
		cin >> input;
	}
	
	return 0;
}