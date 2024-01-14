#include <iostream>

using namespace std;

void heapify(int arr[], int i, int len){
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;

	if(left < len && arr[left] > arr[largest]){
		largest = left;
	}

	if(right < len && arr[right] > arr[largest]){
		largest = right;
	}

	if(largest != i){
		swap(arr[i],arr[largest]);

		//for testing purposes
		// for(int i = 0; i < len; i++){
		// 	cout << arr[i] << ";	";
		// }
		// cout << endl;
		//for testing purposes

		heapify(arr,largest,len);
	}
}

void buildheap(int arr[],int len){
	for(int i = len/2;  i >= 0; i--){
		cout << "i: " << i << endl;
		heapify(arr,i,len);
	}
}

void heapsort(int arr[],int len){
	buildheap(arr,len);
	for(int i = len - 1; i >= 0; i--){
		swap(arr[0],arr[i]);
		len--;
		heapify(arr,0,len);
	}
}

int main(){
	int size = 0;
	cin >> size;
	int array[size];

	for(int i = 0; i < size; i++){
		cin >> array[i];
	}

	//for testing purposes
	// for(int i = 0; i < size; i++){
	// 	cout << array[i] << ";	";
	// }
	// cout << endl;
	//for testing purposes

	heapsort(array,size);

	for(int i = 0; i < size; i++){
		cout << array[i] << ';';
	}

	return 0;
}