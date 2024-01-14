#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
	//create new Stack
	Stack s;
	//take an input on how many elements in stash
	int num;
	cin >> num;

	//initialize stack
	s.initialize();

	//create array of doubles to store numbers to add to stack and save their addresses
	double numarr[num];
	for(int i = 0; i < num; i++){
		//take in a double and put it into the ith spot in numarr
		double input;
		cin >> input;
		numarr[i] = input;
	}

	//loop for every element
	for(int i = 0; i < num; i++){
		//convert double into double* and then into void*
		void* in = (double*)(&numarr[i]);
		//push into stack
		s.push(in);
 	}

 	//loop for every elements
	for(int i = 0; i < num; i++){
		//convert void* to double* back to double
		double out = *(double*)s.peek();
		//print the number in the stack
		cout << out << endl;
		//pop from stack
		s.pop();
	}

	//clean up stack
	s.cleanup();

	return 0;
}