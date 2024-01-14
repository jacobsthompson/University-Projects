#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Sortable.h"

class Data{
	std::vector<Sortable*> v;
public:
	void add(Sortable* number){
		v.push_back(number);
	}
	void sort(){
		for(int i = 0; i < v.size()-1; i++){
			int min = i; 
			for(int j = i+1; j < v.size(); j++){
				if(v[j]->compare(v[min])){
					min = j;
				}
			}
			if(min != i){
				Sortable* temp = v[i];
				v[i] = v[min];
				v[min] = temp;
			}
		}
	}
	void print(){
		for(int i = 0; i < v.size();i++){
			v[i]->print();
		}
		std::cout << std::endl;
	}
};