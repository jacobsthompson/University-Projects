#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int l, int r){
	int P = r;
	int index = l;
	for(int i = l; i < r; i++){
		if(arr[i] < arr[P]){
			swap(arr[i],arr[index]);
			index++;
		}
	}
	swap(arr[P],arr[index]);
	return index;
}

int randomP(int arr[], int l, int r){
	int n = rand();		//using <cstdlib>
	int P = l + n%(r-l+1);
	swap(arr[r],arr[P]);
	return partition(arr,l,r);
}

void quicksort(int arr[], int l, int r){
	int P;
	if(l < r){
		P = randomP(arr,l,r);
		quicksort(arr,l,P-1);
		quicksort(arr,P+1,r);
	}
}


int main(){
	int size = 0;
	cin >> size;
	int array[size];

	for(int i = 0; i < size; i++){
		cin >> array[i];
	}

	quicksort(array,0,size-1);

	for(int i = 0; i < size; i++){
		cout << array[i] << ';';
	}

	return 0;
}