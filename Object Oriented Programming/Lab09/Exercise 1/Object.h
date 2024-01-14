#pragma once

class Object{
public:
	//create but don't initialize static int count
	static int count;
	//default constructor, add 1 to count when ran
	Object(){
		count++;
	}
	//copy constructor using const Object &o
	Object(const Object &o){
		count++;
	}
};