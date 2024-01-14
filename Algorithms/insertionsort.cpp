#include <iostream>

using namespace std;

int main(){
	//create and take in amount of items in array
	int amount = 0;
	cin >> amount;
	
	//create array and input numbers into array
	int nums[amount];
	for(int i = 0; i < amount; i++){
		cin >> nums[i];
	}
	
	//create count so we know how many items are in list for printing out results
	int count = 1;

	//loop through entire list excluding the first element bc we need at least 1 element to compare with
	for(int i = 1; i < amount; i++){

		//increase count (more numbers in sorted list)
		count++;

		//set temp variable to current i number in num
		int temp = nums[i];

		//have a variable set as the place behind i (aka the previous number in the list)
		int j = i - 1;

		
		//will loop as long as the index j is not at the start of the list and the temp value is smaller than the last value
		while(j >= 0 && temp <= nums[j]){

			//shifts numbers over
			nums[j+1] = nums[j];

			//moves on to next place in array
			j--;
		}

		//inserts value in correct spot
		nums[j+1] = temp;

		//prints out current sorted list based on count
		for(int i = 0; i < count; i++){
			cout << nums[i] << ";";
		}
		cout << endl;
	}

	

	return 0;
}
