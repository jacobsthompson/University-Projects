#include <iostream>

using namespace std;

//takes in the adress of num
void triple(int& num){
	//creates a pointer to the int num
	int* p = &num;
	//deferences and multiplies itself by 3, changing num
	*p = *p * 3;
}

int main( int argc, const char * argv[] )
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	triple(num);

	cout << num << endl;

	return 0;
}