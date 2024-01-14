#pragma once

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Circle{
private:
	//delcare x, y, radius
	double x;
	double y;
	double r;
public:
	//default constructer of unit cirlce centered at origin
	Circle() {
		x = 0;
		y = 0;
		r = 1;
	}
	//constructer to take in x, y, r values
	Circle(double xx, double yy, double rr){
		x = xx;
		y = yy;
		r = rr;
	}
	//get fucntions return x, y, or r
	double getX(){
		return x;
	}

	double getY(){
		return y;
	}

	double getR(){
		return r;
	}
	//get area returns πr^2
	double getArea(){
		return M_PI * r * r;
	}
	//set functions set x,y,r to new x,y,r values
	void setX(double xx){
		x = xx;
	}

	void setY(double yy){
		y = yy;
	}

	void setR(double rr){
		r = rr;
	}
};