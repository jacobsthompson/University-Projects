#include <iostream>
#include <cstdlib>

using namespace std;

//partition based on page 171 psudocode
int partition(int arr[], int p, int r){
	int X = arr[r];
	cout << X << ';';
	int i = p - 1;
	for(int j = p; j < r; j++){		//only change to psudocode is j < r-1 to j < r, as results were wrong
		if(arr[j] <= X){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i + 1;
}

//random select based on page 216 psudocode
int randomselect(int arr[], int p, int r, int i){
	if(p == r){
		return arr[p];
	}
	int q = partition(arr,p,r);
	int k = q - p + 1;
	if(i == k){
		return arr[q];
	} else if (i < k){
		return randomselect(arr,p,q-1,i);
	} else return randomselect(arr,q+1,r,i-k);

}


int main(){
	int size = 0;
	cin >> size;
	int array[size];
	int i = 0;
	cin >> i;

	for(int i = 0; i < size; i++){
		cin >> array[i];
	}

	cout << randomselect(array,0,size-1,i) << ';';

	return 0;
}