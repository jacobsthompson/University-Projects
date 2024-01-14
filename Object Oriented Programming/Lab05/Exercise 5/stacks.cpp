#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, const char * argv[])
{
	cout << "s1\n";
	{
		Stack s1;
		for( int i = 1; i < 5; i++ )
			s1.push( double(i)/2.0 );
		s1.cleanup();
	}

	cout << endl;

	cout << "s2\n";
	{
		Stack s2(4);
	}

	cout << "\nend\n";

	return 0;
}