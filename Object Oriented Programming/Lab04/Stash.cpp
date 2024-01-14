#include <iostream>
#include "Stash.h"

using namespace std;

int main(){
	//create new stash
	Stash s;
	//take an input on how many elements in stash
	int num;
	cin >> num;

	//initialize stash to store doubles
	s.initialize(sizeof(double));
	//loop through for every element
	for(int i = 0; i < num; i++){
		//take in a double
		double input;
		cin >> input;
		//convert double into double*
		double* addnum = &input;
		//add to stash
		s.add(addnum);
 	}

 	//loop through stash
	for(int i = 0; i < s.count(); i++){
		//set void* temp to the ith stash element
		void* temp = s.fetch(i);
		//print by converting to double* deferencing
		cout << *(double*)(temp) << endl;
	}

	//cleap up stash
	s.cleanup();

	return 0;
}