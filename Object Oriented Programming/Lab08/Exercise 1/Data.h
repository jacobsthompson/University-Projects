#pragma once
#include <iostream>
#include <vector>

class Data{
	std::vector<int> v;
public:
	void add(int number){
		v.push_back(number);
	}
	void sort(){
		std::sort(v.begin(),v.end());
	}
	void print(){
		for(int i = 0; i < v.size();i++){
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
};