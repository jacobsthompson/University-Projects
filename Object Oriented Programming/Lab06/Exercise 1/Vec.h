#pragma once

#include <iostream>

class Vec{
public:
	float x;
	float y;
	Vec(){
		x = 0;
		y = 0;
	}

	Vec(float newx, float newy){
		x = newx;
		y = newy;
	}

	void set(float setx, float sety){
		x = setx;
		y = sety;
	}

	void add(Vec v){
		x += v.x;
		y += v.y;
	}

	void print(){
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};