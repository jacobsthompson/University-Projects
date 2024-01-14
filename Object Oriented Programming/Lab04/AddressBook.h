#pragma once

#include <iostream>

//same as Exersice 5
struct Entry{
	std::string name;
	std::string lastname;
	std::string email;
	//added next pointer to keep track of entries
	Entry* next;

	std::string getName(){ return name; }
	std::string getLastname(){ return lastname; }
	std::string getEmail(){ return email; }
	void setName(std::string n){ name = n; }
	void setLastname(std::string n){ lastname = n; }
	void setEmail(std::string n){ email = n; }
	void print(){ std::cout << getName() << " " << getLastname() << ": " << getEmail() << std::endl; }
};

struct AddressBook{
	//create head (start of address book)
	Entry* head;
	//initialize makes head a new entry and sets its name to ""
	AddressBook(){
			head = new Entry;
			//set name to "" so we can tell later if head has data put into it
			head->setName("");
	};

	//will add a Entry to end of AddressBook
	void add(Entry* address){
		//if head is "" (hasn't had any data put into it)
		if(head->name == ""){
			//set head = address
			head->setName(address->getName());
			head->setLastname(address->getLastname());
			head->setEmail(address->getEmail());
		} else {
			//if head is already an entry
			//make temp entry* equal to head
			Entry* temp = head;
			//loop until end of list
			while(temp->next != NULL){
				//increment temp
				temp = temp->next;
			}
			//now set the last entries next to the new entry
			temp->next = address;
		}
	}

	//print full Address Book
	void print(){
		//create temp head
		Entry* temp = head;
		//loop until temp is the end of list
		while(temp != NULL){
			//Entry print() temp
			temp->print();
			//increment temp
			temp = temp->next;
		}
	}

	//no cleanup function asked for

};