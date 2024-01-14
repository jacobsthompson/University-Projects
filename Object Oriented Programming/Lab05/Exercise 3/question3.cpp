#include <iostream>
#include <vector>
#include <string>
#include "display.h"
#include "Dog.h"

using namespace std;

//NOTE: I COULD NOT FIGURE OUT HOW TO DISABLE THE DECONSTRUCTORS OF ANIMAL AND DOG, SO OUTPUT IS SLIGHTLY DIFFERENT THAN EXPECTED RESULTS
//AS IT INCLUDES DESTROYING DOG AND DESTROYING GENERIC ANIMAL OUTPUTS

int main(){
	//take input of N (how many elements to put into vector)
	int N;
	cin >> N;

	//create Animal* vector
	vector<Animal *> v;
	//loop N times
	for(int i = 0; i < N; i++){
		//temp variables from char type (A or D), string name, and int age (both to be inputted into Class)
		char type;
		string name;
		int age;
		//take inputs
		cin >> type;
		cin >> name;
		cin >> age;
		//if the class type is Animal:
		if(type == 'A'){
			//create a new Animal*
			Animal* animal = new Animal;
			//set name and age
			animal->setName(name);
			animal->setAge(age);
			//push Animal* into vector
			v.push_back(animal);
		//if the class type is Dog:
		} else if(type == 'D'){
			//create new Dog, intilialize with name and age
			Dog dog = Dog(name, age);
			//upcast into Animal*
			Animal* upcastdog = &dog;
			//push Animal* into vector
			v.push_back(upcastdog);
		}
	}

	//display the vector values
	display(v);
}