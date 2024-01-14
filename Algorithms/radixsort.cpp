#include <iostream>
#include <cstdlib>

using namespace std;
const int z = 10;

void countsort(int arr[][z], int size, int c){
	//create a tally array that can count the digits 0-9
	int tally[10] = {0,0,0,0,0,0,0,0,0,0};
	//create a new array that we do the sorting to
	int sorted[size][z];

	//tally up the cth collumn
	for(int i = 0; i < size; i++){
		tally[arr[i][c]]++;
	}

	//create cumulative frequency
	for(int i = 1; i < 10; i++){
		tally[i] += tally[i-1];
	}

	//loop through all rows
	for(int i = size - 1; i >= 0; i--){
		//for loop used to copy entire row
		for(int j = 0; j < z; j++){
			//place the correct cth digit in its sorted column
			sorted[tally[arr[i][c]]-1][j] = arr[i][j];
		}
		//adjust cumulative frequency tally
		tally[arr[i][c]]--;
	}

	//copy sorted array to our original array
	for(int i = 0; i < size; i++){
		for(int j = 0; j < z; j++){
			arr[i][j] = sorted[i][j];
		}
	}
}

void radixsort(int arr[][z],int size){

	//loop through every column to sort
	for(int j = z-1; j >= 0; j--){
		countsort(arr,size,j);
	}
}


int main(){
	int size = 0;
	cin >> size;
	int array[size][z];

	for(int i = 0; i < size; i++){
		for(int j = 0; j < z; j++){
			cin >> array[i][j];
		}
	}

	radixsort(array,size);

	for(int i = 0; i < size; i++){
		for(int j = 0; j < z; j++){
			cout << array[i][j] << ';';
		}
		cout << endl;
	}

	return 0;
}