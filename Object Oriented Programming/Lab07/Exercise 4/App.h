#pragma once
#include <iostream>

//class Rect that has a default constructor and an x,y,w,h constructor
class Rect{
public:
	float x, y, w, h;
	Rect(){};
	Rect(float newx, float newy, float neww, float newh){ x = newx; y = newy; w = neww; h = newh; }
};

//base AppWindow class
class AppWindow{
protected:
	//uses default constructor to make a Rect
	Rect box;
public:
	//default constructor sets box.x,y,w,h to 0
	AppWindow(){ box.x = 0; box.y = 0; box.w = 0; box.h = 0; }
	//constructor that sets box.x,y,w,h to inputted x,y,w,h
	AppWindow(float x, float y, float w, float h) { box.x = x; box.y = y; box.w = w; box.h = h; }
	//constructor that takes in a Rect and assignes the r.x,y,w,h to our box.x,y,w,h
	AppWindow(const Rect& r) { box.x = r.x; box.y = r.y; box.w = r.w; box.h = r.h; }
	//get rect returns the current rect
	const Rect& get_rect() { return box; }
	//virtual void resize sets base with an input of width and height to be rewritten by children
	virtual void resize(int w, int h){};

};

//CircleWin Class
class CircleWin: public AppWindow{
protected:
	//radius of circle = width
	float radius;
public:
	//default constructor inherited from AppWindow
	CircleWin() : AppWindow(){}
	//constructor inherited from AppWindow
	CircleWin(float x, float y, float w, float h) : AppWindow(x,y,w,h){
		//does AppWindow(x,y,w,h)
		//then sets the radius to the max of w & h
		if(w  >= h){ radius = w; } else { radius = h; }
	}
	//constructor that takes in a Rect inherited from AppWindow
	CircleWin(const Rect& r) : AppWindow(r){
		//does AppWindow(r)
		//then sets the radius to the max of r.w & r.h (the inputted rects width and height)
		if(r.w  >= r.h){ radius = r.w; } else { radius = r.h; }
	}
	//resize takes in a new width and height
	void resize(int w, int h){
		//finds the max of new w and h and sets radius to max
		if(w  >= h){ radius = w; } else { radius = h; }
		//print the radius
		std::cout << "radius: " << radius << std::endl;
	}

};
//RectWin Class
class RectWin: public AppWindow{
protected:
	//float area = width * height
	float area;
public:
	//default constructor inherited from AppWindow
	RectWin() : AppWindow(){}
	//constructor inherited from AppWindow
	RectWin(float x, float y, float w, float h) : AppWindow(x,y,w,h){
		//does AppWindow(x,y,w,h)
		//then sets area to width times height
		area = w * h;
	}
	//constructor that takes in a Rect inherited from AppWindow
	RectWin(const Rect& r) : AppWindow(r){
		//does AppWindow(r)
		//then sets area to r.w * r.h (the inputted rects width and height)
		area = r.w * r.h;
	}
	//resize takes in a new width and height
	void resize(int w, int h){
		//sets area to new width times new height
		area = w * h;
		//prints area
		std::cout << "area: " << area << std::endl;
	}
};