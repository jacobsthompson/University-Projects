#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//the purpose of this code is to take in ints until 0 is inputted. 
//if a negative number is inputted, remove all positive values equal to the absolute value of the inputted negative number

int main(){
	vector<int> v;

	//take in a number
	int curr;
	cin >> curr;

	//loop until curr is zero
	while(curr != 0){
		//if curr is positive, add curr to vector
		if(curr > 0){
			v.push_back(curr);
		} else {
			//if curr is negative, remove all values from v equal to the absolute value of curr. (-5 removes 5)
			for(int i = 0; i < v.size(); i++){
				if(abs(v[i]) == abs(curr)){
					v.erase(v.begin()+i);
				}
			}
		}
		//new input
		cin >> curr;
	}

	//print the size of v, aka how many elements are in v still
	cout << v.size() << endl;
	//add up all numbers in v and print the total
	int total = 0;
	for(int i = 0; i < v.size(); i++){
		total += v[i];
	}
	cout << total << endl;
	
	return 0;
}