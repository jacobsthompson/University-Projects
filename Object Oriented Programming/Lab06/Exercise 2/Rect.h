#pragma once

#include <iostream>
#include "Vec.h"

class Rect{
public:
	float x, y, w, h;
	Rect(float newx, float newy, float neww, float newh){
		x = newx;
		y = newy;
		w = neww;
		h = newh;
	}

	bool contains(Vec v){
		if(v.x >= x && v.x <= x+w && v.y <= y && v.y >= y-h){
			return true;
		} else {
			return false;
		}
	}
};