#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog() : Animal() {
	}

	Dog( std::string n, int a ) : Animal( n, a ) {
	}

	void talk() {
		std::cout << "Woof, woof!" << std::endl;
	}
};

#endif