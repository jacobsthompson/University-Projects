#pragma once
#include <iostream>
#include "Sortable.h"

class Circle : public Sortable {
public:
	float radius;
	Circle(){
		radius = 0;
	};
	Circle(float r){
		radius = r;
	}
	bool compare(const Sortable* s){
		Circle* c = (Circle*)s;
		if(radius < c->radius){ return true; } else { return false; }
	}
	void print(){
		std::cout << "Circle with radius: " << radius << std::endl;
	};

};