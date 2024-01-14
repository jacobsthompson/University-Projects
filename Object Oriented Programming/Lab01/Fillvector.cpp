#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> v;
	ifstream in( "code.cpp" );
	string line;
	
	while( getline( in, line ) ) // getline returns true if read successfully
		v.push_back( line ); // add the line to the end of v

	// print normal
	for( int i = 0; i < v.size(); i++ )
		cout << i << ": " << v[i] << endl;
	//print reversed
	for( int i = v.size()-1; i >= 0; i-- )
		cout << i << ": " << v[i] << endl;
}