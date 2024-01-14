#pragma once
#include <iostream>

class Time{
private:
	int hours, minutes, seconds;
public:
	//constructor
	Time(int h, int m, int s){
		hours = h;
		minutes = m;
		seconds = s;
	}
	//destructor
	~Time(){}

	//get and set fucntions
	int getHour(){ return hours; }
	int getMin(){ return minutes; }
	int getSec(){ return seconds; }
	void setHour(int x) {hours = x; }
	void setMin(int x) {minutes = x; }
	void setSec(int x) {seconds = x; }

	//+ operator: timez = timex + timey
	const Time operator+( const Time& t) const {
		//overflow variables for seconds and minutes over 60 (mover = over 60 seconds, hover = over 60 minutes)
		int hover = 0;
		int mover = 0;
		//set new s (seconds) to this objects seconds plus t's seconds
		int s = seconds + t.seconds;
		//while s is over 60, remove 60 seconds and add 1 minute to mover
		while(s >= 60){ s -= 60; mover++; }
		//set new m (minutes) to this objects minutes plus t's minutes plus the overflow minutes (mover)
		int m = minutes + t.minutes + mover;
		//while m is over 60, remove 60 minutes and add 1 hour to hover
		while(m >= 60){ m -= 60; hover++; }
		//set new h (hours) to this objects hours plus t's hours plus the overflow hours (hover)
		int h = hours + t.hours + hover;
		//while h is over 24, remove 24 each loop
		while(h >= 24){ h -= 24;}
		//return the new Time object with the new hour, minute, and second values
		return Time(h,m,s);
	}

	const Time& operator++(){
		//increment this Time objects hours
		this->hours++;
		//return this time with the new incremented (permanent) hour value
		return *this;
	}

	const Time operator++(int){
		//create copy of this Time object
		Time temp(*this);
		//increament this Time objects hours
		this->hours++;
		//return the original Time object without the incremented hour
		return temp;
	}

	void print(){
		//print out hours, minutes, seconds
		std::cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << std::endl;
	} 
};