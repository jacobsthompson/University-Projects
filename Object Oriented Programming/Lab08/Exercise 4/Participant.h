#pragma once
#include <iostream>
#include <string>
#include "Sortable.h"

class Participant: public Sortable{
public:
	std::string name;
	int age;
	double score;
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
		if(score > p->score){
			return true; 
		} else if(score < p->score) { 
			return false;
		} else {
			if(age < p->age){
				return true;
			} else if(age > p->age){
				return false;
			} else {
				if(name[0] < p->name[0]){
					return true;
				} else {
					return false;
				}
			}
		}
	}
};