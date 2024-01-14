#include <iostream>
#include "Circle.h"

int main( int argc, const char * argv[] )
{
	Circle myCircle;

	cout << "Center:\t(" << myCircle.getX() << ", " << myCircle.getY() << ")" << endl;
	cout << "Radius:\t" << myCircle.getR() << endl;
	cout << "Area:\t" << myCircle.getArea() << endl;

	myCircle.setX(1);
	myCircle.setY(2);
	myCircle.setR(3);

	cout << endl;
	cout << "Center:\t(" << myCircle.getX() << ", " << myCircle.getY() << ")" << endl;
	cout << "Radius:\t" << myCircle.getR() << endl;
	cout << "Area:\t" << myCircle.getArea() << endl;
	
	Circle anotherCircle( 5.5, 10.10, 20.20 );
	
	cout << endl;
	cout << "Center:\t(" << anotherCircle.getX() << ", " << anotherCircle.getY() << ")" << endl;
	cout << "Radius:\t" << anotherCircle.getR() << endl;
	cout << "Area:\t" << anotherCircle.getArea() << endl;

	return 0;
}