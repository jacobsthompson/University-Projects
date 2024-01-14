#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	//take in first input and second input and store in x and y
	int x, y;
	cout << "First input: ";
	cin >> x;
	cout << "Second input: ";
	cin >> y;
	
	//create 2 pointers that point to the address of x and y respectively
	int *px = &x;
	int *py = &y;

	//deference px and py and add, subtract, multiply, and divide
	cout << "Added: "  << *px + *py << endl;
	cout << "Subbed: " << *px - *py << endl;
	cout << "Multed: " << *px * *py << endl;
	//convert *px and *py to floats before dividing so it's outputted as a float
	cout << "Divved: " << float(*px) / float(*py) << endl;

	return 0;
}