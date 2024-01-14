#pragma once

#include <iostream>

//struct for individual links
struct Link {
	//have a void* for data in the link, and a Link* for the next link
	void* data;
	Link* next;
			
	//initialize data and next
	void initialize(void* dat, Link* nxt) {
		data = dat;
		next = nxt;
	}
};

//struct for Linked List
struct LinkedList {
	//create a head of Linked List
	Link* head;

	//initialize Linked list
	LinkedList(void* dat) {
		//make head a new Link with dat stored in it
		head = new Link;
		head->initialize(dat,NULL);
	};

	//add a link into the linked list
	void add(Link* l, int n){
		//set a temp head link to where the adding will start
		Link* h = l;
		//repeat process n times
		for(int i = 0; i < n; i++){
			//create temp link and initialize it with the value i
			Link* temp = new Link;
			int* d = new int(i);
			//set the temp next to what temp heads next currently is
			temp->initialize(d,h->next);
			//set the new temp head next to the link we just made
			h->next = temp;
			//incrememt h to the next link
			h = h->next;
		}
	}

	void print(){
		//if linkedlist empty
		if(head == NULL){
			std::cout << "Linked List Empty" << std::endl;
		} else {
			//create temp link starting at head
			Link* temp = head;
			//print the data in the head link by converting to int* and dereferencing
			std::cout << *(int*)(temp->data) << std::endl;
			//loop until we reach end of list
			while(temp->next != NULL){
				//print data in temp->next
				std::cout << *(int*)(temp->next->data) << std::endl;
				//increment temp
				temp = temp->next;
			}
		}
	}

	//clean up
	void cleanup(){
		//while the head link still exists
		while(head){
			//set temp to head
			Link* temp = head;
			//set head to whats infront of head
			head = temp->next;
			//delete temp (original head)
			delete temp;
		}
		//once done print Cleaned Up
		std::cout << "Cleaned Up" << std::endl;
	}
};

