#include <iostream>
#include <string>

#include "Data.h"
#include "Circle.h"
#include "Participant.h"

using namespace std;

int main( int argc, const char* argv[] )
{
	Data myData;

	//input = Q, C, T, S, P
	string input;
	//Circle Radius
	int radius;
	//Participant Name, Age, Score
	string name;
	int age;
	int score;
	//take in original input
	cin >> input;
	//while input is not quit
	while(input != "Q" || input != "q"){
		//if input is cirlce
		if(input == "C" || input == "c"){
			//take in a radius, add to myData, and print Cirlce Added
			cin >> radius;
			myData.add(new Circle(radius));
			cout << "Circle added" << endl;
		//if input is participant
		} else if(input == "T" || input == "t"){
			//take in name, age, score, add to myData, and print Participant Added
			cin >> name;
			cin >> age;
			cin >> score;
			myData.add(new Participant(name,age,score));
			cout << "Participant added" << endl;
		//if input is sort
		} else if(input == "S" || input == "s"){
			//sort myData, print Data Sorted
			myData.sort();
			cout << "Data sorted" << endl;
		//if input is print
		} else if(input == "P" || input == "p"){
			//print myData
			myData.print();
		//if input is quit
		} else if(input == "Q" || input == "q"){
			//break out of loop
			break;
		}
		//take in new input
		cin >> input;
	}
	
	// myData.add( new Participant( "Waymond", 24, 100 ) );
	// myData.add( new Circle() );
	// myData.add( new Participant( "Mary", 27, 96 ) );
	// myData.add( new Circle( 3 ) );
	// myData.add( new Participant( "John", 32, 100 ) );
	// myData.add( new Circle( 2 ) );
	// myData.add( new Participant( "Eliza", 21, 105 ) );
	// myData.add( new Circle( 4 ) );
	// myData.add( new Participant( "Ezekiel", 27, 96 ) );
	// myData.add( new Circle( 1 ) );
	// myData.add( new Participant( "Alex", 20, 101 ) );

	// myData.print();
	// myData.sort();
	// myData.print();

	return 0;
}