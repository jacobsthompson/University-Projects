#pragma once

#include <iostream>
#include "Vec.h"

class Rect{
public:
	//take in an x pos, y pos, width, and height
	float x, y, w, h;
	//constructor takes in new x y w h and sets them to rect x y w h
	Rect(float newx, float newy, float neww, float newh){
		x = newx;
		y = newy;
		w = neww;
		h = newh;
	}
	//contains checks if a vec (x,y) coords are in the bounds of the rect, returns bool
	bool contains(Vec v){
		//checks if x <= v.x <= x+w (the coord w to the right) and y-h (the coord h down) <= v.y <= y
		if(v.x >= x && v.x <= x+w && v.y <= y && v.y >= y-h){
			return true;
		} else {
			return false;
		}
	}
};