#include <iostream>
#include <string>

#include "Data.h"
#include "Participant.h"

using namespace std;

bool sortByName( const Participant* p1, const Participant* p2 ) {
	return p1->name < p2->name;
}

bool sortByAge( const Participant* p1, const Participant* p2 ) {
	return p1->age < p2->age;
}

bool sortByScore( const Participant* p1, const Participant* p2 ) {
	return p1->score > p2->score;
}

bool (*Participant::comp_cb) (const Participant*, const Participant*) = NULL;

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

	Participant::comp_cb = &sortByName;
	myData.sort();
	myData.print();

	Participant::comp_cb = &sortByAge;
	myData.sort();
	myData.print();

	Participant::comp_cb = &sortByScore;
	myData.sort();
	myData.print();

	return 0;
}