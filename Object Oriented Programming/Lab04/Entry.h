#pragma once

#include <iostream>

struct Entry{
	//initialize 3 strings: name, lastname, email
	std::string name;
	std::string lastname;
	std::string email;

	//the get___ functions will return the string value it's associated with
	std::string getName(){
		return name;
	}

	std::string getLastname(){
		return lastname;
	}

	std::string getEmail(){
		return email;
	}

	//the set____ functions with make the string it's associated with equal to n
	void setName(std::string n){
		name = n;
	}

	void setLastname(std::string n){
		lastname = n;
	}

	void setEmail(std::string n){
		email = n;
	}

	//prints using the get functions, prints Name Lastname : email
	void print(){
		std::cout << getName() << " " << getLastname() << ": " << getEmail() << std::endl;
	}

};