#pragma once
#include <iostream>
#include <string>
#include "Sortable.h"

class Participant: public Sortable{
public:
	std::string name;
	int age;
	double score;
	static bool (*comp_cb)(const Participant*, const Participant*);
	Participant(std::string n, int a, double s){
		name = n;
		age = a;
		score = s;
	}
	void print(){
		std::cout << name << "\t" << age << "\t" << score << std::endl;
	}
	bool compare(const Sortable* s){
		Participant* p = (Participant*)s;
		if(comp_cb(this,p)){return true;} else {return false; }
	}
};