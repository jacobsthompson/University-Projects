#include <iostream>

using namespace std;

//the purpose of this code is to print the character c n-times until n is inputted as negative

int main(){
	//input a character and a number
	char c;
	int n;
	cin >> c >> n;

	//loop until n is negative
	while(n >= 0){
		//if n = 0, print new line (print c 0 times)
		if(n == 0){
			cout << endl;
		} else {
			//if n > 0, print out c n-times
			for(int i = 0; i < n; i++){
				cout << c;
			}
			cout << endl;
		}
		//take in new input
		cin >> c >> n;
	}
	
	return 0;
}