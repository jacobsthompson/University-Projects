#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
protected:
	string name;
	int age;

public:
	//add a public static int count
	static int count;
	Animal() {
		cout << "Creating Generic Animal" << endl;
		name = "Generic Animal";
		age = 0;
		//everytime an animal instance is created, increase count by 1
		count++;
	}
	
	~Animal() {
		cout << "Deleting Generic Animal" << endl;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getAge() {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	void feed() {
		cout << "Some food, please!" << endl;
	}
};
