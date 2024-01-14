#pragma once

#include <iostream>

class Vec{
public:
	//x and y coords
	float x;
	float y;
	//default constructor set both x y to 0
	Vec(){
		x = 0;
		y = 0;
	}

	//constructor with inputs for x y
	Vec(float newx, float newy){
		x = newx;
		y = newy;
	}
	//set takes two float inputs and sets them to x and y
	void set(float setx, float sety){
		x = setx;
		y = sety;
	}
	//add takes in another vector, and adds the 2 x and y components and stores them into main vec
	void add(Vec v){
		x += v.x;
		y += v.y;
	}
	//prints x and y coord
	void print(){
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};