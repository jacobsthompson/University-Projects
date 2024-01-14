#pragma once

#include "Animal.h"

//create Dog class that inherits Animal Class
class Dog : public Animal{
public:
	//default constructor
	Dog(){
		cout << "Creating Dog" << endl;
	}
	//dog constructor that takes in a name and age
	Dog(string newname, int newage){
		cout << "Creating Dog" << endl;
		name = newname;
		age = newage;
	}
	//dog deconstructor prints Deleting Dog
	~Dog(){
		cout << "Deleting Dog" << endl;
	}
	//dog feed that prints Dog food, please!
	void feed(){
		cout << "Dog food, please!" << endl;
	}
};