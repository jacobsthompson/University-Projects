#include <iostream>

using namespace std;

bool Prime(int n){
	//check if n is 0 or 1
	if(n <= 1){ return false; }
	//starting loop at 2, going up until i = n, this loop checks if n can be divided by any number other than 1
	for(int i = 2; i < n; i++){
		//if number is divisable by i, its not prime and returns false
		if(n % i == 0){
			return false;
		} 
	}
	//if n was not divisible by any number between 2 and n, it is prime.
	return true;
}

int main(){
	//take input number
	int n;
	cin >> n;

	//starting at i = 1, going up until i > n, this loop will print out prime numbers equal to i, and i is always smaller than n
	for(int i = 1; i <= n; i++){
		//check if i is a prime number
		if(Prime(i)){
			//output i
			cout << i << " ";
		}
	}

	return 0;
}