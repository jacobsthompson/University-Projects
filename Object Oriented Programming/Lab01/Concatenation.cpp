#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> v;
	ifstream in( "code.cpp" );
	string line;
	string fullText = "";
	
	while(getline(in,line)){
		v.push_back( line );
	}

	// print normal
	for( int i = 0; i < v.size(); i++ ){
		fullText += v[i] + "\n";
	}

	cout << fullText << endl;
}