#include <iostream>
#include <math.h>

using namespace std;

//recursively prints out binary version of int using cout
void binary(int x){
	if(x > 1){ binary(x/2); }
	cout << x % 2;
}

//this function turns an int into binary, and stores all of its digits in an array
void binary(int n, int arr[]){
	int i = 0;
	//runs through until n = 0, meaning it's been divided by it's amount of x's in 2^x
	while (n > 0){
		//set the ith value of the array to either 0 or 1 depending on n % 2
		arr[i] = n % 2;
		//divide n by 2
		n = n/2;
		//increase the ith position
		i++;
	}
}

//finds the bit of n in binary at the index position starting from the right side
int getBit(int n, int index){
	//find the length of n in binary using log2n+1
	int len = int(log2(n)+1);
	//create array of len length
	int barr[len];
	//run binary array function
	binary(n, barr);
	//return the index-th digit in the binary array
	return barr[index];
}

int setBit(int n, int index){
	//find length of n in binary
	int len = int(log2(n)+1);
	//create new array
	int barr[len];
	//run binary array function
	binary(n, barr);

	//set the bit at position index to 1
	barr[index] = 1;

	//loop through binary array backwards and print it out
	for(int i = len -1; i >= 0; i--){
		cout << barr[i];
	}
	return 0;
}

int clearBit(int n, int index){
	//find length of n in binary
	int len = int(log2(n)+1);
	//create new array
	int barr[len];
	//run binary array function
	binary(n, barr);

	//set the bit at position index to 0
	barr[index] = 0;

	//loop through binary array backwards and print it out
	for(int i = len -1; i >= 0; i--){
		cout << barr[i];
	}
	return 0;
}

int main(){
	//take input of the number and the position
	int n;
	int index;
	cout << "Number: ";
	cin >> n;
	cout << "Position: ";
	cin >> index;
	
	//print out n in binary
	cout << "Binary representation of " << n << " is ";
	//run binary function
	binary(n);
	cout << endl;

	//print the bit at position index using getBit
	cout << "Get bit at index "<< index << ": " << getBit(n, index) << endl;

	//print out n in binary with the index-th bit set to 1
	cout << "Binary number after setting bit at index " << index << ": ";
	//run setBit
	setBit(n, index);
	cout << endl;

	//print out n in binary with the index-th bit set to 0
	cout << "Binary number after clearing bit at index " << index << ": ";
	//run clearBit
	clearBit(n, index);
	cout << endl;

	return 0;
}