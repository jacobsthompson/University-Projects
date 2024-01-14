#include <iostream>
#include <string>

#include "Data.h"
#include "Participant.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	Data myData;

	myData.add( new Participant( "Waymond", 24, 100 ) );
	myData.add( new Participant( "Mary", 27, 96 ) );
	myData.add( new Participant( "John", 32, 100 ) );
	myData.add( new Participant( "Eliza", 21, 105 ) );
	myData.add( new Participant( "Ezekiel", 27, 96 ) );
	myData.add( new Participant( "Alex", 20, 101 ) );

	myData.print();
	myData.sort();
	myData.print();

	return 0;
}