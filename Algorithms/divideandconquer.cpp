#include <iostream>

using namespace std;

//returns the higher value of x and y
int max(int x, int y){
	if(x >= y){
		return x;
	} else {
		return y;
	}
}

//returns the highest value of x y and z, by using the previous max
int max(int x, int y, int z){
	return max(max(x,y),z);
}

//finds the maximum sum in the array that the middle is included in
int crossingMax(int a[], int l, int m, int h){
	//left side
	int sum = 0;
	int lsum = 0;
	for(int i = m; i >= 1; i--){
		sum += a[i];
		if (sum > lsum){
			lsum = sum;
		}
	}

	//right side
	sum = 0;
	int rsum = 0;
	for(int i = m; i <= h; i++){
		sum += a[i];
		if(sum > rsum){
			rsum = sum;
		}
	}

	//returns the sums
	return max(lsum+rsum-a[m],lsum,rsum);
}

//the recursive part to find the maxmum sum subarray
int subarrayMax(int a[], int l, int h){
	//checks if invalid range
	if (l > h){
		return 0;
	}

	//checks if theres only one element
	if (l == h){
		return a[l];
	}

	//finds the middle
	int m = (l+h)/2;

	//returns if the highest sum is in the left side, right side, or the middle section
	return max(subarrayMax(a,l,m-1),subarrayMax(a,m+1,h),crossingMax(a,l,m,h));
}

int main() {

	//input size of array
	int size = 0;
	cin >> size;
	int numbers[size];

	//fill array with values
	for(int i = 0; i < size; i++){
		cin >> numbers[i];
	}

	//return maximum subarray
	cout << subarrayMax(numbers,0,size);

	return 0;
}