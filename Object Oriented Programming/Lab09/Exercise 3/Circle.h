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
		//dynamic cast const Sortable* s to const Circle* c
		const Circle* c = dynamic_cast<const Circle*>(s);
		//if c == 0, the cast is not the same, so return true (circle is smaller)
		if(c == 0){
			return true;
		} else {
			if(radius < c->radius){ return true; } else { return false; }
		}
	}
	void print(){
		std::cout << "Circle with radius: " << radius << std::endl;
	};

};